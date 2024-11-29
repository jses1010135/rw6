﻿// rw6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

// rw6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//



int main()
{
	
	FILE* file; // 宣告檔案指標
	errno_t err = fopen_s(&file,"input.txt", "w"); // 開啟檔案
	if (err != 0) { // 如果開啟檔案失敗
		std::cout << "開啟檔案失敗！" << std::endl; // 輸出錯誤訊息
		return 0; // 程式結束
	}

	int a = 0; // 宣告整數變數 a
	int* s; // 宣告指標變數 s
	int n; // 宣告整數變數 n
	std::cin >> n; // 從標準輸入讀取整數 n m,

	s = new int[n]; // 動態分配 n 個整數的陣列

	for (int i = 0; i < n; i++)std::cin >> s[i]; // 從標準輸入讀取 n 個整數並存入陣列 s 中
	
	for (int i = 0; i < n-1; i++) // 進行氣泡排序
		for (int j = 0; j < n - 1 - i; j++)
			if (s[j] > s[j + 1]) {
				int temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		
	
	
	
	for (int i = 0; i < n; i++)fprintf(file, "%d", s[i]); // 將陣列 s 中的 n 個整數輸出到檔案

		
	
	delete[]s; // 釋放動態分配的記憶體*\/
    fclose(file);
	}

    


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
