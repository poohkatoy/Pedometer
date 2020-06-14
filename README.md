# Pedometer
คือ เครื่องนับจำนวนคนแบบจำกัดจำนวนคนที่เข้าไปใช้สถานที่ ต้องกดปุ่มเปิด/ปิด เพื่อให้เครื่องเริ่มทำงาน เป็นเครื่องที่จะคอยนับจำนวนคนที่เข้ามาใช้สถานที่ใดสถานที่หนึ่งด้วยระบบอัติโนมัติ ซึ่งช่วงนี้เราต้องจำกัดจำนวนคนของแต่ละสถานที่ เพื่อไม่ให้เกิดการแออัดในช่วงที่โควิด-19 กำลังระบาดนี้ เครื่องนี้จะให้คนเข้าสถานที่ได้ไม่เกิน 20คน เมื่อคนที่1เดินผ่าน บนจอแสดงผลจะแสดงเลข1 คนที่2 ก็จะเป็นเลข2 ... คนที่20ก็จะเป็นเลข20 ระหว่างนี้ถ้ามีคนเดินออก ตัวเลขที่แสดงบนหน้าจอก็จะถูกลบออกไปครั้งละ 1คน เมื่อคนที่21เดินผ่าน หน้าจอจะแสดงเลข21 และหน้าจออีกจอจะแสดงผลว่า"ไม่สามารถเข้าพื้นที่นี้ได้" และจะมีเสียงสัญญาณดังึ้น และไฟ LED จะติดเป็นเวลา 2วินาที หากต้องการปิดเครื่องให้กดปุ่มเปิด/ปิดอีกครั้ง

## ที่มาและความสำคัญ
ในการนับคนที่จะเข้าไปใช้สถานที่แต่ละที่นั้นอาจจะดูไม่ยุ่งยากนัก แต่เนื่องจากสถานการณ์ที่มีโรคระบาด(โควิด-19) ที่จะต้องมีการจำกัดจำนวนคนที่เข้าไปใช้สถานที่ ดังนั้นจึงทำให้เกิดปัญหาในเรื่องของเวลา แทนที่ลูกจ้างจะไปให้บริการกับลูกค้า ก็ต้องมายืนนับคนที่หน้าร้าน เพื่อเช็คจำนวนคนที่เข้า-ออกร้านบางทีอาจจะลืมจำนวนคนที่ได้นับไปแล้วจนเป็นสาเหตุให้นับผิดได้

ด้วยเหตุนี้ ผู้จัดทำจึงแก้ไขปัญหานี้โดยการทำเครื่องนับจำนวนคนแบบอัตโนมัติขึ้นมา เพื่อไม่ให้ลูกจ้างและนายจ้างเสียเวลาไปกับการนับจำนวนคนเข้า-ออกร้านค้า นอกจากนี้เครื่องนับจำนวนคนอัตโนมัติยังสามารถนำไปให้ในสถานที่อื่นได้อีกด้วย อย่างเช่นโรงเรียน เป็นต้น
        
## กลุ่มเป้าหมาย
        - ผู้ประกอบการร้านค้าขนาดย่อม เช่น ร้านอาหาร ร้านสะดวกซื้อ เป็นต้น
        - ผู้บริหารสถานศึกษา
        
## รายละเอียดโปรเจค
### Perception Module
        - Button
        - Ultrasonic 2 ชุด
### Behavior
        - กดปุ่ม เพื่อเปิด/ปิดตัวเครื่อง
	- เครื่องนับจำนวนคนจะทำงานอัตโนมัติ
	- เครื่องนับจำนวนคน สามารถนับจำนวนคนเข้าสถานที่ได้20คน
	- เครื่องนับจำนวนคนจะนับทั้งคนเข้าและออกจากสถานที่
	- เครื่องนับจำนวนคนจะมีเสียงแจ้งเตือน และมีสัญญาณไฟเตือน หากคนในสถานที่เกิน20คน

### Manipulation Module
        - I2C Digit 7-Segment Display
        - Relay Module+LED
        - Passive buzzer บนบอร์ด
        - 2.4” TFT Resistive Touch HMI Screen
### โครงสร้างพื้นฐาน

![alt text For Logo 1][flowchart]

[flowchart]: https://github.com/poohkatoy/Pedometer/blob/master/image/Flowchart.svg "Flowchart"

### ระบบการทำงาน

![alt text For Logo 2][diagram]

[diagram]: https://github.com/poohkatoy/Pedometer/blob/master/image/diagram.jpg "Diagram"
