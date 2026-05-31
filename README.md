# PetPad [WIP]
<img width="1920" height="1080" alt="PetPad Repo Cover v0" src="https://github.com/user-attachments/assets/fd22ae49-4e91-4df7-a477-ac6726181eb8" />

Custom Made Tamagotchi Like Device

## Features

### Physical
1. USB - C rechargeable 500 mAh battery
2. 3 Tactile buttons for control
3. Buzzer for sound feedback
4. 128x64 OLED Screen

### Digital
1. [WIP] Multiple Pets to obtain
2. Take care (or dont) of your pets to see the visuals change
3. [WIP] Use items obtained randomly on your pets for effects

## Why?
I wanted to create this for a couple of reasons:
1. I wanted a more complex project to work on
2. Tamagochis are fun and allow me to practice some pixel art skills too
3. and finally because there was a great guide on the fallout docs :)

## The PCB
The PCB was made in KiCAD due to the extensive tools and ablity to import own footprints that might not be on EasyEDA

### The Schematic
<img width="1074" height="805" alt="image" src="https://github.com/user-attachments/assets/028acbca-4915-4a2e-b609-9bfe3dfdbc85" />

### The Circuit Board

**Front**


<img width="603" height="847" alt="image" src="https://github.com/user-attachments/assets/293aed44-49d1-4aa3-a59a-64843eab9f33" />

**Back**


<img width="597" height="860" alt="image" src="https://github.com/user-attachments/assets/3d0ea54c-da11-483c-93a1-c0100afb5243" />

## The Case

**Overview**



<img width="949" height="709" alt="image" src="https://github.com/user-attachments/assets/e08d1e05-0cfd-4af1-86b1-571a161c40e4" />


**Top**


<img width="549" height="778" alt="image" src="https://github.com/user-attachments/assets/cc2db98a-4f17-4f37-b970-50be607f5556" />


**Inside cut**


<img width="1703" height="602" alt="image" src="https://github.com/user-attachments/assets/145f2468-1c70-4d1c-9984-f44c0ee7a6a7" />

**Bottom**


<img width="471" height="732" alt="image" src="https://github.com/user-attachments/assets/4f5b7f19-6045-4567-8b34-3bd0e5b7a91b" />

## The Firmware
<img width="832" height="446" alt="Firmware Video" src="https://github.com/user-attachments/assets/d2fcfda3-3c85-4c98-bc8f-e3dd0d67888c" />


Visible stats that change over time with visual feedback on overall pets health


## BOM
*Amount used is to make ***ONE*** PetPad*

| Item | LCSC # / Item Links | Single Cost | Amount Used | Fees/Notes | Total Price |
| -------- | -------- | -------- | -------- | -------- | -------- |
| **PCB:** | -------- | $2 | 1 | $3.12 for shipping | $5.12 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| **Components:** | -------- | -------- | -------- | -------- | -------- |
| OLED Screen | [C5248080](https://www.lcsc.com/product-detail/C5248080.html?spm=wm.gwc.xh.0.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECEgBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $2.32 | 1 | -------- | $2.32 |
| Buzzer | [C49246964](https://www.lcsc.com/product-detail/C49246964.html?spm=wm.gwc.xh.1.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECEgBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0569 | 1 | Forced to buy 10 | $0.57 |
| Buttons | [C2888493](https://www.lcsc.com/product-detail/C2888493.html?spm=wm.gwc.xh.2.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECEgBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0107 | 3 | Forced to buy 50 | $0.54 |
| JST Battery Connector | [C131337](https://www.lcsc.com/product-detail/C131337.html?spm=wm.gwc.xh.3.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECEgBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0336 | 1 | Forced to buy 20 | $0.67 |
| 7 Pin Header | [C5360900](https://www.lcsc.com/product-detail/C5360900.html?spm=wm.gwc.dh.4.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECEgBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0391 | 2 | Forced to buy 10 | $0.39 |
| 4 Pin Header | [C42431787](https://www.lcsc.com/product-detail/C42431787.html?s_z=n_q_PZ2.54-1*4&spm=wm.fly.bg.10.xh&lcsc_vid=TgBXAwYAFVlYUAdXQVhcUVUFQABXXlJeElANBlxRQAIxVlNRTlFbUVRRQ1VcVDsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D) | $0.0207 | 1 | Forced to buy 20 | $0.41 |
| Seeed Studio XIAO C6 DIP | [Amazon](https://www.amazon.com/ESP32C6-Supports-Bluetooth-802-15-4-Microsoft/dp/B0D2NKVB34?th=1) | $11.99 | 1 | $0.79 tax | $12.78 |
| Battery (500mAh) | [AliExpress](https://www.aliexpress.us/item/3256808031709894.html?channel=twinner ) | $5.90 | 1 | NOTE: WELCOME DEAL USED, NORMAL PRICE $14.23 | $5.90 |
| Screws (M2.5 x 5mm) | [Homedepo](https://www.homedepot.com/p/Prime-Line-M2-5-0-45-x-5-mm-Grade-A2-70-Stainless-Steel-Phillips-Drive-Pan-Head-Metric-Machine-Screws-10-Pack-9130825/311229791?MERCH=REC-_-rv_search_plp_rr-_-n/a-_-0-_-n/a-_-n/a-_-n/a-_-n/a-_-n/a) | $0.433 | 4* | 10 pack | $4.33 |
| Wires | [Adafurit](https://www.adafruit.com/product/3169) | $4.95 | less than a foot most likely | Silicone Cover Stranded-Core Wire - 50ft 30AWG | $4.95 |
| Case PLA | -------- | $8.34 for 1 kg | -------- | Generic 3D printer PLA. Requires a 3D printer to use | -------- |
| -------- | -------- | -------- | -------- | -------- | -------- |
| *Total:* | -------- | -------- | -------- | -------- | $17.29* |
| **Fees:** | -------- | -------- | -------- | -------- | -------- |
| Shipping | -------- | -------- | -------- | -------- | $9.32 |
| Handling | -------- | -------- | -------- | -------- | $3 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| ***GRAND TOTAL*** | -------- | -------- | -------- | -------- | [WIP] |

## How to use
[WIP]

## Software Used
1. KiCAD
2. Autodesk Fuesion
3. Blender
4. Visual Studio Code (Arduino Maker Workshop & Wokwi extentsions)
5. Arduino IDE
6. Adobe Photoshop
7. Adobe Preimire Pro
8. Visual Studio Code
