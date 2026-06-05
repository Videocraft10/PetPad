# PetPad [WIP]
<img width="3840" height="2160" alt="PetPad Main" src="https://github.com/user-attachments/assets/411f9951-f100-48c6-bf89-5794ea4fa645" />


Custom-Made Tamagotchi-Like Device

## Features
<img width="2480" height="3508" alt="Videocraft PetPad Zine v1" src="https://github.com/user-attachments/assets/accfe757-8549-40c8-867c-5013030798f9" />


### Physical
1. USB - C rechargeable 500 mAh battery
2. 3 Tactile buttons for control
3. Buzzer for sound feedback
4. 128x64 OLED Screen

### Digital
1. [WIP] Multiple Pets to obtain
2. Take care (or don't) of your pets to see the visuals change
3. [WIP] Use items obtained randomly on your pets for effects

## Why?
I wanted to create this for a couple of reasons:
1. I wanted a more complex project to work on
2. Tamagotchis are fun and allow me to practice some pixel art skills too
3. And finally, because there was a great guide on the Fallout docs :)

## The PCB
The PCB was made in KiCAD due to the extensive tools and ability to import own footprints that might not be on EasyEDA

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
*Amount used is to make ****ONE**** PetPad*

| Item | LCSC # / Item Links | Single Cost | Amount Used | Fees/Notes | Total Price |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **PCB:** | ---------- | $2 | 1 | $3.12 for shipping | $5.12 |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **Components:** | ---------- | ---------- | ---------- | ---------- | ---------- |
| OLED Screen | [C5248080](https://www.lcsc.com/product-detail/C5248080.html?spm=wm.gwc.xh.0.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECegBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $2.32 | 1 | ---------- | $2.32 |
| Buzzer | [C49246964](https://www.lcsc.com/product-detail/C49246964.html?spm=wm.gwc.xh.1.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECegBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0569 | 1 | Forced to buy 10 | $0.57 |
| Buttons | [C2888493](https://www.lcsc.com/product-detail/C2888493.html?spm=wm.gwc.xh.2.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECegBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0107 | 3 | Forced to buy 50 | $0.54 |
| JST Battery Connector | [C131337](https://www.lcsc.com/product-detail/C131337.html?spm=wm.gwc.xh.3.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECegBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0336 | 1 | Forced to buy 20 | $0.67 |
| 7 Pin Header | [C5360900](https://www.lcsc.com/product-detail/C5360900.html?spm=wm.gwc.dh.4.cbm___wm.mly.ssl.gwc&lcsc_vid=QwcNU1RVElVcAVECegBfXwdeFFZXVlUDQlMMBlFRRFQxVlNRQVZfV1NeRFVYVzsOAxUeFF5JWBYZEEoKFBINSQcJGk4NBhYS) | $0.0391 | 2 | Forced to buy 10 | $0.39 |
| 4 Pin Header | [C42431787](https://www.lcsc.com/product-detail/C42431787.html?s_z=n_q_PZ2.54-1*4&spm=wm.fly.bg.10.xh&lcsc_vid=TgBXAwYAFVlYUAdXQVhcUVUFQABXXlJeElANBlxRQAIxVlNRTlFbUVRRQ1VcVDsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFBIk%3D) | $0.0207 | 1 | Forced to buy 20 | $0.41 |
| Seeed Studio XIAO C6 DIP | [Amazon](https://www.amazon.com/ESP32C6-Supports-Bluetooth-802-15-4-Microsoft/dp/B0D2NKV334?th=1) | $11.99 | 1 | $0.79 tax | $12.78 |
| Battery (500mAh) | [AliExpress](https://www.aliexpress.us/item/3256808031709894.html?channel=twinner) | $1.06 | 1 | NOTE: INSANE SUMMER DEAL USED, NORMAL PRICE $14.23 | $1.06 |
| Screws (M2.5 x 5mm) | [Homedepot](https://www.homedepot.com/p/Prime-Line-M2-5-0-45-x-5-mm-Grade-A2-70-Stainless-Steel-Phillips-Drive-Pan-Head-Metric-Machine-Screws-10-Pack-9130825/311229791?MERCH=REC-_-rv_search_plp_rr-_-n/a-_-0-_-n/a-_-n/a-_-n/a-_-n/a-_-n/a-_-n/a) | $0.433 | 4* | 10 pack | $4.33 |
| Wires | [Amazon]([https://www.adafruit.com/product/3169](https://www.amazon.com/Fielect-Enamelled-Winding-Polyurethane-QA-1-155/dp/B082SGDHTT?crid=3POIXT4TOZV8X&dib=eyJ2IjoiMSJ9.w1oH9WPINFywtT7OZmtCDgLDk6IalWVSzi-2-7GuMHuAPawm0k5yT119lFJsF-rJH-uHs1I6qLnd9nLMCaqdH9MYihqoa674noTX4nhzVrpOPF2dk22GB7aIry3RNpuRB0zNbsu97DY79lzWdZ6XJ33oz2e59S97eLn6YiI83coYrCRFQhUi4AvRZS7napdcofGfUDidzUne8SnBlVEOhJjXlK1cI0EN0Mv34Ps6HmY.9FjyuD3y8xoHDIwdMniIMM2knZN64d8aVcBDNQr6chU&dib_tag=se&keywords=30%2Bawg%2Benameled%2Bmagnet%2Bwire&qid=1780683570&sprefix=30%2Bawg%2B%2Caps%2C362&sr=8-4)) | $7.48 | less than a foot most likely (WILL HAVE A TON LEFT OVER SO IF YOU HAVE SOMTHING SIMILAR DO NOT BUY) | 30 AWG Magnet Wire Enameled Copper Wire | $7.45 |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| *Total:* | ---------- | ---------- | ---------- | ---------- | $37.98 |
| **Fees:** | LCSC Tax $1.25 | ---------- | ---------- | ---------- | [wip] |
| Shipping | LCSC Shipping cost: $10.92 | ---------- | ---------- | ---------- | [wip]|
| Handling | LCSC Handling $3 | ---------- | ---------- | ---------- | $3 |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| ***TOTAL*** | ---------- | ---------- | ---------- | ---------- | $50.30 (fee prices not locked in yet) |

## Build BOM
| Item | Discripton | Notes | Fees | -------- | Total |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| 3D Printer PLA | Generic 3D printer PLA. Requires a 3D printer to use | Paid $8.34 for 1 kg | ---------- | ---------- | 46g used - $0.38 |
| Sodering Iron | ---------- | Required to soder on components | ---------- | ---------- | $10.55 [here](https://www.amazon.com/Soldering-Digital-Welding-Portable-Electric/dp/B08R3515SF?crid=30SL6CYRR5QOM&dib=eyJ2IjoiMSJ9.tKWBCBm44gyjNSvFj51RHR3p5aTdCOPIkPv4zqdgg07Moy7biWvfE6YjBdwHnsMMUqJ5p1WsD_MQe5r0XLalW_yVXgv5tx_TBmzJ2sAt1If-sll8ak-_muURnXvGQ8DVMdb2n-LQRQO0gSH2GR3nmbYitK2dPQ3w6Pu08Y6wdY2s8pWVOnGJz7T9gRpbqCr_TALWvgprG9lNvJy1RXWeywEfL33os00Syai0ic4byZ-FLX-ZYRh2TATM8PfFfGRYe0N_YCACfh6VRKp0zii5u79dBTlHN-xO9SU5h5X_axQ.4EqxHoftylAQD1t5h9kA999EhPS51LAq9y_vrFTic5Y&dib_tag=se&keywords=soldering%2Biron&qid=1780680980&sprefix=sodering%2Bir%2Caps%2C290&sr=8-6&th=1) |
| ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| ***TOTAL*** | ---------- | ---------- | ---------- | ---------- | $10.93 |


***GRAND TOTAL*** = $60.68


## How to Build
> [!NOTE]
> It is recommended to have prior knowledge in electronics and soldering if you want to create one for yourself!

First download the PCB Gerber file from [here](https://github.com/Videocraft10/PetPad/tree/main/PCB%20Files) then send it to your preferred manufacturer! Next buy all of the components from the BOM. For screws and similar items, it is recommended to find the cheapest in your location. Next 3D print the case from here [here](https://github.com/Videocraft10/PetPad/tree/main/Case%20Files) and ensure the PCB fits once it arrives. Next solder on all of the components and screw the PCB into the case! Finally flash the firmware onto it from [here](https://github.com/Videocraft10/PetPad/tree/main/Firmware%20Files/PetPad_Firm) (you might have to build the file on you own computer)

Tada! You now have a PetPad!

(instructions on how to build will improves once I actually phisaclly build one myself :D)


## Software Used
1. KiCAD
2. Autodesk Fusion
3. Blender
4. Visual Studio Code (Arduino Maker Workshop & Wokwi extentsihons)
5. Arduino IDE
6. Adobe Photoshop
7. Adobe Preimimre Pro
8. Visual Studio Code
