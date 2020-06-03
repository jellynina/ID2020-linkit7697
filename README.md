# 建旭老師工業設計的機器人遊樂園
*整理by ikea*

1. Linkit 7697
2. Robot Shield
3. Linkit remote

# 環境安裝

1. Arduino IDE, 並且新增以下URL增加對 **7697** 的支援 [setup 文件](https://docs.labs.mediatek.com/resource/linkit7697-arduino/zh_tw/environment-setup)
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```


# Linkit 7697基本語法與ＧＰＩＯ設定
GPIO 預設腳位狀態 [文件](https://docs.labs.mediatek.com/resource/linkit7697-arduino/zh_tw/developer-guide/initial-pin-state-of-linkit-7697)


## 問題
```
#define R_PIN A3    // P17  why?
#define G_PIN A2    // P16
#define B_PIN A1    // P15 
```
1. GPIO腳位對照[表格](https://docs.labs.mediatek.com/resource/linkit7697-arduino/zh_tw/developer-guide/initial-pin-state-of-linkit-7697)，數字跟範例不一樣，目前嘗試將`A1`改成`58`仍可以使用
  > 不是16進位，A1 = 161



# LRemote基本語法
```
#include <LRemote.h> //呼叫LRemote Lib
```




## Controller 型態[文件](https://docs.labs.mediatek.com/resource/linkit7697-arduino/en/developer-guide/using-linkit-remote/lremote-control-classes)

These control classes are provided to create UI controls to the canvas created by LRemote:
- `LRemoteLabel`: a static text label
- `LRemoteButton`: a rectangular button with a text label
- `LRemoteCircleButton`: a round, circular button with a text label
- `LRemoteSlider`: a slider with adjustable range and initial value
- `LRemoteSwitch`: a on/off switch
- `LRemoteJoystick`: an analog joystick control

## Controller Methods:

### `updateText()`


---

#Things TO BE doen:

- [x] IDE使用 `VS code`
  目前有 `偵測到 #include 錯誤。請更新您的 includePath。此編譯單位 (/Users/ikea/Documents/Arduino/sketch_rgb_linkit_7697/sketch_rgb_linkit_7697.ino) 的波浪線已停用。`
  也就是原本Arduino IDE可以讀到的Lib的路徑跟在`vs code`裡面的不一樣。
  **解**： 要把LinkIt路徑加入`includePath`中 在檔案 `c_cpp_properties.json` 參考[vs-code arduino issue](https://github.com/microsoft/vscode-arduino/issues/438)
  ```
  /Users/USERNAME/Library/Arduino15/packages/LinkIt
  ```

- [x] 完成RGB slider作業
  因為元件是 **共陽** 所以RGB數值是反的。
- [ ] ＯＴＴＯ機器人實作研究