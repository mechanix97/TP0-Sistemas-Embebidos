# Documentación basic-firmware-educiaa

En este documento se detallará la estructura de la libreria board, cuyo código puede encontrarse en el siguiente  [repositorio](https://github.com/LautaroEst/basic-firmware-educiaa/tree/master/libs/board).

## Estructura del repositorio
```bash
board
├── edu_ciaa_nxp
│   ├── inc
│   │   ├── board.h
│   │   └── board_api.h
│   └── src
│       ├── board.c
│       └── board_sysinit.c
├── lib
│   ├── flat.ld
│   ├── libs.ld
│   ├── link.ld
│   └── mem.ld
├── lpc_chip_43xx
│   ├── inc
│   │   └── ...
│   ├── src
│   │   └── ...
│   ├── usd_rom
│   │   └── ...
│   └── software content register.txt
lpc_startup
│   └── src
│       ├── crp.c
│       ├── sysinit.c
│       └── vendor_interrupt.c
module.mk
```

## edu_ciaa_nxp/inc

En esta carpeta se encuentran los archivos .h que incluyen la configuración básica de la placa. Por ejemplo, contiene la configuración de los pines de la placa. Además se incluye las firmas de funciones básicas para encender o apagar pines de salida.

## edu_ciaa_nxp/src

Por otro lado, en esta carpeta se encuentran las implementaciones de las funciones cuya firma fueron definidas en la carpeta anterior. Estas funciones se encargan de inicializar la placa y todos sus modulos cuando se enciende.

## lib
En este directorio se incluyen archivos destinados a controlar el grabado en la memoria de la placa de los programas que se vayan a cargar.

## lpc_chip_43xx/inc
Aca se tienen los archivos de cabecera de las interfaces los modulos internos de la placa tales como el ADC o el timer entre otros.

## lpc_chip_43xx/src
En el directorio anterior se tenia los archivos de cabecera, mientras que en este se tienen las implementaciones de estos modulos.

## lpc_chip_43xx/usbd_rom
En esta carpeta se tienen las declaraciones de la conexión USB de la placa.

## lpc_startup/src
En esta carpeta se tiene otras configuraciones de la placa como también la función inicializadora de la placa y la defición del vector de interrupciones con sus correspondientes 'handlers'.
