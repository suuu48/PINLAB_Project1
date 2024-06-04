![header](https://capsule-render.vercel.app/api?type=soft&color=006EDB&fontColor=DEEAF7&height=200&section=header&text=PIN_LAB&desc=Project%201&descAlignY=80&fontSize=90)
# PIN_LAB: Project 1

ATM program linked Google Cloud MySQL based on C++ 

---

## Navigation
1. [Description](#Description)
2. [Getting started](#Getting-Started)

---

## Description
ATM program linked Google Cloud MySQL based on C++ 
- ATM program
    - (User) Deposit, Withdraw, Remit, Check balance, Update bankbook, Create account, Change password 
    - (Admin) Account suspension and suspension cancellation, Change password
- linked GCP MySQL

### FlowChart
<img src="https://user-images.githubusercontent.com/76460405/204080701-7a2f605b-9c45-490c-bacc-5139b4572afa.png" width="333" height="411">

---

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 
See deployment for notes on how to deploy the project on a live system.

### Installing & Setting
#### Integrating MySQL with C++ (On Visual Studio)
1. 프로젝트 > 속성 > 구성 속성 > V/C++ 디렉터리 > 포함 디렉터리: Add path MySQL's include directory
2. 프로젝트 > 속성 > 구성 속성 > V/C++ 디렉터리 > 라이브러리 디렉터리: Add path MySQL's lib directory
3. 프로젝트 > 속성 > 구성 속성 > 링커 > 입력 > 추가 종속성: Add "libmysql.lib;"
4. ```#include <mysql.h>```

#### Connecting [Google Cloud Platform](https://console.cloud.google.com)
<img src="https://user-images.githubusercontent.com/76460405/204081577-94c0420a-916c-41d4-b797-e86e99438f9e.png" width="422" height="276">

---

## Stacks
<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=C++&logoColor=white"> <img src="https://img.shields.io/badge/MySQL-4479A1?style=for-the-badge&logo=MySQL&logoColor=white"> <img src="https://img.shields.io/badge/Google Cloud-4285F4?style=for-the-badge&logo=Google Cloud&logoColor=white">
