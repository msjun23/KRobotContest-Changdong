# KRobotContest-Changdong
> - ## KRobotContest with ROBIT at Changdong Youth Center
>
> - ## 서울시립창동청소년센터에서 진행하는 **K로봇대회 with 로빛** 에서 사용하는 타이머 프로그램과 사용법입니다.

---

임베디드 보드로 **아두이노 우노(또는 R3 호환보드)**를 사용합니다.
![arduino_uno](/image/arduino_uno.png)

---

# 1. 라인트레이서, 미션형창작(초, 고급), 블록코딩(초, 고급)

## 1.1 계측기 센서
**라인트레이서, 미션형창작(초, 고급), 블록코딩(초, 고급)** 세 종목에는 출발지점과 도착지점에 각각 계측기를 위치시킵니다. 계측기 센서는 다음 센서를 사용합니다.

![IR_sensor](/image/IR_sensor.png)
[https://www.devicemart.co.kr/goods/view?no=1341808](https://www.devicemart.co.kr/goods/view?no=1341808)

> ### 센서 선 정보
>> 갈색: VCC(5V)</br>
>> 파란색: GND</br>
>> 검은색: SIGNAL

## 1.2 아두이노 핀 배치
- **출발지점** 계측기는 **5번** 디지털 핀에 연결합니다.
- **도착지점** 계측기는 **6번** 디지털 핀에 연결합니다.

출발지점에 물체가 인식되면 타이머가 시작되고, 도착지점에 물체가 인식되면 타이머가 멈춥니다.

## 1.3 타이머 프로그램
**/KROBOT-Timer-LINETRACER/Timer.exe** 프로그램을 실행하면 타이머 프로그램이 실행됩니다.

![img1](/image/img1.png)
![img2](/image/img2.png)

![timer1](/image/timer1.png)

> 1. 우측의 *Scan* 버튼을 누르면 다음과 같은 창이 뜹니다.</br>
> ![scan1](/image/scan1.png) </br>
> *확인*을 누른 후 *Port:* 우측의 콤보 박스를 누르면, 현재 컴퓨터에 연결된 장치를 확인할 수 있습니다.
>
>> 연결된 포트가 여러 개라면, 윈도우 검색창에 *장치 관리자*를 검색한 후, *포트(COM & LPT)*를 확인하여 아두이노가 연결된 포트를 확인할 수 있습니다.
>>
>> ![manager1](/image/manager1.png)
>> ![manager2](/image/manager2.png)
>>
> 아두이노가 연결된 포트를 선택한 후 *Connect* 버튼을 누르면 연결됩니다.
> 
> ![timer2](/image/timer2.png)
>
> 2. *Start* 버튼을 누르면 우측의 *state*가 *Ready*로 바뀌고 *Start*버튼이 비활성화됩니다. 이때 출발지점의 계측기를 지나면 타이머가 시작합니다.
>
> ![timer3](/image/timer3.png)
> ![timer4](/image/timer4.png)
>
> 3. 도착지점의 계측기를 지나면 타이머가 종료됩니다. 동시에 우측의 *state*가 *End*로 바뀝니다.
> ![timer5](/image/timer5.png)
> 
> 4. *Reset* 버튼을 누르면 타이머가 초기화되며, *2, 3*번을 반복하여 타이머를 동작시킬 수 있습니다.
>

---

# 2. 로봇슈팅
## 2.1 스위치 센서
## 2.2 아두이노 핀 배치

로봇슈팅 종목은 A팀, B팀 양측에서 누가 먼저 미션을 완료하는지 대결하는 종목입니다. 각 팀에 해당하는 두 개의 타이머를 사용합니다.
- **A팀** 계측기는 **2번** 디지털 핀에 연결합니다.
- **B팀** 계측기는 **3번** 디지털 핀에 연결합니다.

## 2.3 타이머 프로그램
![timer2_1](/image/timer2_1.png)
> 기본적인 동작은 [1.3 타이머 프로그램](https://github.com/msjun23/KRobotContest-Changdong#13-%ED%83%80%EC%9D%B4%EB%A8%B8-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8)과 동일합니다.
> 1. *Start* 버튼을 누르면 타이머가 시작합니다.
>
> 2. 각 팀이 압력판을 터치하면 각 팀의 랩 타임이 표시됩니다.
>> * 양측 모두 랩 타임이 표시되어도 타이머는 계속 흐릅니다.
>
> 3. *Stop* 버튼을 누르면 타이머가 멈춥니다.
>
> 4. *Reset* 버튼을 누르면 타이머가 초기화되고, 양 팀의 랩 타임이 지워집니다.
