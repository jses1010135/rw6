#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    FILE* file; // 宣告檔案指標
    errno_t err = fopen_s(&file, "input.txt", "w"); // 開啟檔案
    if (err != 0) { // 如果開啟檔案失敗
        std::cout << "開啟檔案失敗！" << std::endl; // 輸出錯誤訊息
        return 0; // 程式結束
    }

    int n = 41; // 設定整數變數 n 為 41
    int* s = new int[n]; // 動態分配 n 個整數的陣列

    

    for (int i = 0; i < n; i++) {
        s[i] = rand() % 100; // 生成 0 到 99 之間的亂數並存入陣列 s 中
    }

    for (int i = 0; i < n - 1; i++) // 進行氣泡排序
        for (int j = 0; j < n - 1 - i; j++)
            if (s[j] > s[j + 1]) {
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }

    fprintf(file, "%d ", n); // 將數字的個數輸出到檔案的第一個數字
    for (int i = 0; i < n; i++) fprintf(file, "%d ", s[i] % 100); // 將陣列 s 中的 n 個整數除以 100 的餘數輸出到檔案

    delete[] s; // 釋放動態分配的記憶體
    fclose(file); // 關閉檔案
}
