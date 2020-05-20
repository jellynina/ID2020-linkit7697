# 建旭老師工業設計的機器人遊樂園
*整理by ikea*

## 作業小專案 - RGB燈

# Linkit 7697基本語法與ＧＰＩＯ設定

## 問題
```
#define R_PIN A3    // P17  why?
#define G_PIN A2    // P16
#define B_PIN A1    // P15 
```
GPIO腳位對照[表格](https://docs.labs.mediatek.com/resource/linkit7697-arduino/zh_tw/developer-guide/initial-pin-state-of-linkit-7697)，數字跟範例不一樣，目前嘗試將`A1`改成`58`仍可以使用
> 不是16進位，A1 = 161



# LRemote基本語法

---

#Things TO BE doen:

-[x] IDE使用 `VS code`
  目前有 `偵測到 #include 錯誤。請更新您的 includePath。此編譯單位 (/Users/ikea/Documents/Arduino/sketch_rgb_linkit_7697/sketch_rgb_linkit_7697.ino) 的波浪線已停用。`
  也就是原本Arduino IDE可以讀到的Lib的路徑跟在`vs code`裡面的不一樣。
  **解**： 要把LinkIt路徑加入`includePath`中 在檔案 `c_cpp_properties.json` 參考[vs-code arduino issue](https://github.com/microsoft/vscode-arduino/issues/438)
  ```
  /Users/USERNAME/Library/Arduino15/packages/LinkIt
  ```

- [] 完成RGB slider作業
- [] ＯＴＴＯ機器人實作研究