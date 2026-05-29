/*
 * 作業說明對應位置索引：
 *  [需求1] Student 結構作為鏈結串列節點  → 第 17-28 行  (struct Student)
 *  [需求2] 動態新增與刪除，不受陣列大小限制 → 第 49-75 行  (add_student / delete_student)
 *  [需求3] 命令列介面：新增/刪除/查詢/儲存 → 第 187-237 行 (main 的 while 迴圈)
 *  [需求4] 第1筆：自己學號與英文姓名；≥3筆測試 → 執行時依序輸入（見程式說明）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID   20 // id 長度
#define MAX_NAME 64 // 英文名稱長度
#define SAVE_FILE "students.dat" // 儲存檔案名稱

/* 
 * [需求1] Student 結構作為鏈結串列的 node 節點
 *  
 *   - id   : 學號
 *   - name : 英文姓名
 *   - next : 指向下一個節點的指標，構成單向鏈結串列
*/
typedef struct Student {
    char id[MAX_ID];
    char name[MAX_NAME];
    struct Student *next;   /* 指向下一個 Student 節點 */
} Student;

/* 
 * [需求2] 動態新增與刪除，不受陣列元素個數限制
 *
 *  每次新增皆呼叫 malloc() 配置一個 Student 大小的記憶體，
 *  因此節點數量僅受系統可用 heap 記憶體限制，
 *  不像陣列必須事先宣告固定大小。
*/

/* 輔助 add_student()：動態配置一個新節點並填入資料*/
static Student *create_node(const char *id, const char *name)
{
    Student *node = malloc(sizeof(Student));    /* heap 動態配置，使節點數不受固定陣列大小限制 */
    if (!node) { perror("malloc"); exit(EXIT_FAILURE); }
    strncpy(node->id,   id,   MAX_ID   - 1); node->id[MAX_ID   - 1] = '\0';
    strncpy(node->name, name, MAX_NAME - 1); node->name[MAX_NAME - 1] = '\0';
    node->next = NULL;
    return node;
}

/* [需求2-新增] 將新節點插入串列尾端（保持輸入順序） */
static void add_student(Student **head, const char *id, const char *name)
{
    Student *node = create_node(id, name);  /* 動態配置，不受陣列大小限制 */
    if (!*head) { *head = node; return; }
    Student *cur = *head;
    while (cur->next) cur = cur->next;      /* 走到尾端 */
    cur->next = node;                       /* 接上新節點 */
}

/* [需求2-刪除] 依學號找到節點，重新接好前後指標後 free() 釋放記憶體
 *   回傳 1 表示刪除成功，0 表示找不到 */
static int delete_student(Student **head, const char *id)
{
    Student *cur = *head, *prev = NULL;
    while (cur) {
        if (strcmp(cur->id, id) == 0) {
            if (prev) prev->next = cur->next;   /* 前節點跳過 cur */
            else      *head      = cur->next;   /* 刪除的是 head */
            free(cur);                          /* 歸還 heap 記憶體 */
            return 1;
        }
        prev = cur;
        cur  = cur->next;
    }
    return 0;
}

/* 依學號查詢，回傳節點指標或 NULL */
static Student *query_student(Student *head, const char *id)
{
    while (head) {
        if (strcmp(head->id, id) == 0) return head;
        head = head->next;
    }
    return NULL;
}

/* ── 顯示所有資料 (查詢 -> 單筆打印) ── */
static void print_student(const Student *s)
{
    printf("  學號: %-15s  姓名: %s\n", s->id, s->name);
}

static void list_all(Student *head)
{
    if (!head) { printf("  (目前無資料)\n"); return; }
    int n = 0;
    printf("  %-3s %-15s %s\n", "No.", "學號", "姓名");
    printf("  %s\n", "------------------------------------");
    while (head) {
        printf("  %-3d %-15s %s\n", ++n, head->id, head->name);
        head = head->next;
    }
    printf("  共 %d 筆\n", n);
}

/* ── 檔案 I/O ── */

/* [需求3-儲存] 將鏈結串列所有節點寫入文字檔 */
static void save_to_file(Student *head, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("fopen"); return; }
    while (head) {
        fprintf(fp, "%s %s\n", head->id, head->name);
        head = head->next;
    }
    fclose(fp);
    printf("  已儲存至 %s\n", filename);
}

/* 啟動時自動從檔案載入，第一次執行若無檔案則略過 */
static void load_from_file(Student **head, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) return;
    char id[MAX_ID], name[MAX_NAME];
    int n = 0;
    while (fscanf(fp, "%19s %63s", id, name) == 2) {
        add_student(head, id, name);
        n++;
    }
    fclose(fp);
    if (n) printf("  已從 %s 載入 %d 筆資料\n\n", filename, n);
}

/* 程式結束前遍歷串列，逐一 free() 所有節點 */
static void free_list(Student *head)
{
    while (head) {
        Student *next = head->next;
        free(head);
        head = next;
    }
}

/* ════════════════════════════════════════════════════════
 * [需求3] 命令列介面：新增 / 刪除 / 查詢 / 儲存
 *
 *  指令  功能
 *  add   呼叫 add_student()    → 新增一筆學生
 *  del   呼叫 delete_student() → 依學號刪除
 *  query 呼叫 query_student()  → 依學號查詢
 *  list  呼叫 list_all()       → 列出所有學生
 *  save  呼叫 save_to_file()   → 儲存至檔案
 *  quit  結束程式
 * ════════════════════════════════════════════════════════ */

static void print_help(void)
{
    printf("  指令列表:\n");
    printf("    add    新增學生\n");
    printf("    del    刪除學生 (依學號)\n");
    printf("    query  查詢學生 (依學號)\n");
    printf("    list   列出所有學生\n");
    printf("    save   儲存至檔案 (%s)\n", SAVE_FILE);
    printf("    help   顯示指令\n");
    printf("    quit   離開程式\n\n");
}

int main(void)
{
    /*
     * [需求4] 測試資料輸入說明：
     *   第 1 筆請輸入自己的學號與英文姓名，例如： 學號: S11234567   姓名: William-Chuang
     *   接著再輸入至少 2 筆其他同學資料，共 ≥ 3 筆，用以驗證新增、刪除、查詢、儲存是否均正常運作。
     */
    Student *head = NULL;
    char cmd[16], id[MAX_ID], name[MAX_NAME];

    printf("=== 學生資料管理系統 (鏈結串列) ===\n\n");
    load_from_file(&head, SAVE_FILE);
    print_help();

    /* [需求3] 主迴圈：讀取指令並分派對應操作 */
    while (1) {
        printf("> ");
        fflush(stdout);

        if (scanf("%15s", cmd) != 1) break;

        if (strcmp(cmd, "add") == 0) {
            /* [需求3-新增] 讀入學號與姓名後呼叫 add_student */
            printf("  學號: "); scanf("%19s", id);
            printf("  姓名: "); scanf("%63s", name);
            if (query_student(head, id)) {
                printf("  錯誤：學號 %s 已存在\n", id);
            } else {
                add_student(&head, id, name);
                printf("  新增成功：%s %s\n", id, name);
            }

        } else if (strcmp(cmd, "del") == 0) {
            /* [需求3-刪除] 讀入學號後呼叫 delete_student */
            printf("  學號: "); scanf("%19s", id);
            if (delete_student(&head, id))
                printf("  刪除成功：學號 %s\n", id);
            else
                printf("  錯誤：找不到學號 %s\n", id);

        } else if (strcmp(cmd, "query") == 0) {
            /* [需求3-查詢] 讀入學號後呼叫 query_student */
            printf("  學號: "); scanf("%19s", id);
            Student *s = query_student(head, id);
            if (s) print_student(s);
            else   printf("  錯誤：找不到學號 %s\n", id);

        } else if (strcmp(cmd, "list") == 0) {
            list_all(head);

        } else if (strcmp(cmd, "save") == 0) {
            /* [需求3-儲存] 將目前串列寫入 students.dat */
            save_to_file(head, SAVE_FILE);

        } else if (strcmp(cmd, "help") == 0) {
            print_help();

        } else if (strcmp(cmd, "quit") == 0) {
            break;

        } else {
            printf("  未知指令 '%s'，輸入 help 查看指令列表\n", cmd);
        }
        printf("\n");
    }

    free_list(head);    /* 釋放所有動態配置的節點記憶體 */
    printf("再見！\n");
    return 0;
}
