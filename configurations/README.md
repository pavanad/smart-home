# Configurations

All configurations of the my home assistant instance

## Sonoff Mini

Perform the flash procedure following the documentation below

https://github.com/arendst/Tasmota/wiki/Sonoff-DIY

Not working with **Sonoff DIY tool_01DIY85**, in MacOS is recommended manual flash

Download firmware and copy in a apache folder
https://github.com/arendst/Tasmota/wiki/Mac-OSX-Local-Web-Server-for-Tasmota-Firmware-Binaries

With postman use the endpoints for flash procedure

example

```
192.168.0.107:8081/zeroconf/ota_flash
```

Body

```
{
	"deviceid": "1000a02117",
	"data": {
		"downloadUrl": "http://192.168.0.109/tasmota-lite.bin",
		"sha256sum": "aa413f499233901f74502558561a1304e2a3d7ab72259740b377f52775adbb5d"
	}
}
```

## Camera model

Intelbras VD16E 480 compatible with 'Q-See QC444 DVR'

Access site https://www.ispyconnect.com/man.aspx?n=q-see&page=0# and click in model **DVR w/ Web Port** (type VLC) for generate URL

```
rtsp://<USER>:<PASSWORD>@<IP>/cam/realmonitor?channel=1&subtype=00&authbasic=<PASSWORD BASE64>
```

