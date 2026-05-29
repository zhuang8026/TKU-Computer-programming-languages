# W14
# 學生資料管理系統（鏈結串列）

## 檔案說明

| 檔案 | 說明 |
|------|------|
| `student_list.c` | 主程式原始碼 |
| `student_list` | 編譯後執行檔（執行 make 後產生） |
| `students.dat` | 儲存學生資料的文字檔（執行 save 後產生） |

---

## 編譯

```bash
gcc -Wall -Wextra -o student_list student_list.c
```

---

## 執行

```bash
./student_list
```

啟動後若 `students.dat` 已存在，會自動載入上次儲存的資料。

---

## 操作 SOP

### 指令列表

| 指令 | 功能 |
|------|------|
| `add` | 新增一筆學生資料 |
| `del` | 依學號刪除一筆資料 |
| `query` | 依學號查詢一筆資料 |
| `list` | 列出目前所有學生資料 |
| `save` | 將資料儲存至 `students.dat` |
| `help` | 顯示指令列表 |
| `quit` | 離開程式 |

---

### 新增學生

```
> add
  學號: S11234567
  姓名: William-Chuang
  新增成功：S11234567 William-Chuang
```

> 第 1 筆請輸入自己的學號與英文姓名。姓名若有空格請用 `-` 連接，例如 `William-Chuang`。

---

### 列出所有學生

```
> list
  No. 學號            姓名
  ------------------------------------
  1   S11234567       William-Chuang
  2   S11234568       Alice-Lin
  3   S11234569       Bob-Chen
  共 3 筆
```

---

### 查詢學生

```
> query
  學號: S11234568
  學號: S11234568        姓名: Alice-Lin
```

---

### 刪除學生

```
> del
  學號: S11234568
  刪除成功：學號 S11234568
```

---

### 儲存資料

```
> save
  已儲存至 students.dat
```

> 離開程式前務必執行 `save`，否則本次新增/刪除的資料不會寫入檔案。

---

### 離開程式

```
> quit
再見！
```

---

## 完整測試流程（SOP）

```
# 1. 編譯
gcc -Wall -Wextra -o student_list student_list.c

# 2. 執行
./student_list

# 3. 新增 3 筆資料（第 1 筆為自己）
> add → 學號: S11234567  姓名: William-Chuang
> add → 學號: S11234568  姓名: Alice-Lin
> add → 學號: S11234569  姓名: Bob-Chen

# 4. 列出確認 3 筆均存在
> list

# 5. 查詢其中 1 筆
> query → 學號: S11234568

# 6. 刪除其中 1 筆
> del → 學號: S11234568

# 7. 再次列出，確認剩 2 筆
> list

# 8. 查詢已刪除的學號，確認回傳「找不到」
> query → 學號: S11234568

# 9. 儲存
> save

# 10. 離開後重新執行，確認資料仍存在
> quit
./student_list
> list
```
