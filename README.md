# Air-quality-monitoring-system
<br><br>
One of the most alarming issues in modern cities is the air quality level, where air pollution has caused 120 deaths out of 100,000 per year based on a worldwide study (Green Car Congress, 2019). The main reason of air pollution is industrial gases emission. <br>
Due to poor air quality, it will increase potential health risks such as risk of stroke, heart disease, lung cancer, asthma and others as well. Hence it becomes mandatory to control the air pollution. <br>
This project is a step towards monitoring the anount co2 present in air. <br><br>
It makes use of Sensor such as MQ135 and NodeMCU ESP8266 Wi-Fi module to send the data to thingspeak where live monitoring of air quality can be done. <br>
Following is the hardware setup for the project.<br><br>
![image](https://user-images.githubusercontent.com/83816588/143426532-a857a196-6d58-47b4-bb60-81b778c058e3.png)
<br><br>
The <i>nodemcu.ino</i> is an arduino code to be uploaded on NodeMCU and to get connected to the thingspeak.<br><br>
Below are some screenshots of the ouput. <br><br>
![image](https://user-images.githubusercontent.com/83816588/143428801-5781c90d-da59-40ce-8867-de93f393049b.png)
<p align = "center">Serial Monitor Output</p> <br><br>

![image](https://user-images.githubusercontent.com/83816588/143429558-63c8c30d-bfe5-477c-bc82-1814285de6f9.png)
<p align = "center">Live Data on thingspeak</p> <br><br>

![image](https://user-images.githubusercontent.com/83816588/143429215-f2cc96be-115a-4364-8abd-982db0a73a19.png)
<p align = "center">CO2 level increases above 60ppm, hence red lamp indicator turned on</p> <br><br>

