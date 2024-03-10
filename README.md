# A dewpoint ventilation based on NodeRed
## Basic calculations

Dewpoint calculation: https://www.wetterochs.de/wetter/feuchte.html



## Hardware

### Raspberry Pi Zero W 2 (for NodeRed)
https://www.berrybase.de/raspberry-pi-zero-2-w#

20 €

### Wemos D1 Mini ESP8266 (for sensors)
https://www.berrybase.de/d1-mini-esp8266-entwicklungsboard-usb-c

5€

With antenna (could improve bad signal):

https://www.berrybase.de/d1-mini-pro-esp8266-entwicklungsboard-mit-u.fl-anschluss-set-mit-antenne

9€


LiPo Shield (for operation without mains voltage):

https://www.berrybase.de/battery/lipo-shield-fuer-d1-mini

4€

https://www.berrybase.de/lp-785060-lithium-polymer/lipo-akku-3-7v-2500mah-mit-2-pin-jst-stecker

8€

### Temperature/Humidity Sensor
#### DHT22
https://www.berrybase.de/dht22-digitaler-temperatur-und-luftfeuchtesensor

6€

Users report inconsistent readings, only 1-2 years lifetime :frowning_face:

#### BME280
https://www.berrybase.de/gy-bme280-breakout-board-3in1-sensor-fuer-temperatur-luftfeuchtigkeit-und-luftdruck

6€

Definitely better than DHT22, but users report self-heating. Temperature readings are 1°-2° C higher than they really are.

#### SHT85
https://de.farnell.com/sensirion/sht85/feuchtigk-temperatursensor-digital/dp/3106917

30€

State of the art sensor for rough envoronments. Expensive, but quality sensor with long lifetime expectation. Used for automobile applications. :warning:: The pin pitch is 1.27 - adapter needed.



### Fans:
tbd

One exhaust fan, one inlet fan. Water/Rain/Rhodent protection needed.

This one hs it all: https://www.iventilatoren.de/fensterlufter-mit-reversmotor-und-automatischen-jalousien-o-237-mm-x11920

### Fan control
Shelly Plus 1PM

https://www.berrybase.de/shelly-plus-1pm-wlan-bluetooth-schaltaktor-mit-messfunktion

18€

### Price estimation
| Device | QTY | SUM |
| -------|-----|-----|
| RasPi | 1 | 20 € |
| RasPi Eqip (Housing, SD, PSU...) | 1 | 30€ |
| D1 Mini | 4 | 20 € |
| SHT85 | 3 | 90 € |
| Shelly | 4 | 72 € |
| Fans | 2 | ? € |
| Material, Cables, Filament... | 1 | 200 € |
| **SUM** | | 432 € |