Document Type: IPF
item: Global
  Version=6.0
  Title English=Telescriber 2.0 Installation
  Flags=00001000
  Languages=0 0 65 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  LanguagesList=English
  Default Language=2
  Japanese Font Name=MS Gothic
  Japanese Font Size=10
  Start Gradient=128 0 255
  End Gradient=128 128 255
  Windows Flags=00010100000000100010110001011000
  Log Pathname=%MAINDIR%\INSTALL.LOG
  Message Font=MS Sans Serif
  Font Size=8
  Disk Filename=SETUP
  Patch Flags=0000000000000010
  Patch Threshold=85
  Patch Memory=4000
  File Version=2.0
  File Description=Telescriber v2.0 Installer
  Company Name=M2 Software Developments & Exports (P) Ltd
  Internal Name=Telescriber
  Original FileName=TelescriberSvc.exe
  Product Name=Telescriber v2.0 Installer
  Product Version=03061314
  FTP Cluster Size=20
  Variable Name1=_SYS_
  Variable Default1=C:\WINNT\System32
  Variable Flags1=00001000
  Variable Name2=_SMSINSTL_
  Variable Default2=C:\Program Files\Microsoft SMS Installer
  Variable Flags2=00001000
  Variable Name3=_ODBC16_
  Variable Default3=C:\WINNT\System32
  Variable Flags3=00001000
  Variable Name4=_ODBC32_
  Variable Default4=C:\WINNT\System32
  Variable Flags4=00001000
end
item: Open/Close INSTALL.LOG
  Flags=00000001
end
item: Check if File/Dir Exists
  Pathname=%SYS%
  Flags=10000100
end
item: Set Variable
  Variable=SYS
  Value=%WIN%
end
item: End Block
end
remarked item: Custom Graphic
  Width=645
  Height=471
  item: Rectangle
    Rectangle=10 0 205 471
    Flags=01010100
    Pen Width=1
    Brush Color=12615680
    Brush Style=1001
  end
  item: Text
    Text English=Telescriber-i
    Text English=
    Rectangle=51 20 211 71
    Flags=01010011
    Pen Color=16776960
    Pen Width=1
    Extra Flags=00000011
    Name=Terminal
    Font Style=-19 0 0 0 700 0 0 0 255 1 2 1 49
  end
  item: Text
    Text English=Telescriber Interactive
    Rectangle=40 44 645 146
    Pen Color=16776960
    Pen Width=1
    Name=Monotype Corsiva
    Font Style=-64 0 0 0 700 1 0 0 0 3 2 1 66
  end
  item: Ellipse
    Rectangle=76 186 128 240
    Flags=01010000
    Pen Color=16776960
    Pen Width=1
    Brush Color=16776960
    Brush Style=1000
  end
  item: Text
    Text English=M
    Rectangle=87 196 129 234
    Pen Color=16776960
    Pen Width=1
    Name=MS Sans Serif
    Font Style=-32 0 0 0 700 0 0 0 0 1 2 1 34
  end
  item: Text
    Text English=2
    Rectangle=113 193 133 218
    Pen Color=16776960
    Pen Width=1
    Name=MS Sans Serif
    Font Style=-11 0 0 0 700 0 0 0 0 1 2 1 34
  end
end
item: Set Variable
  Variable=APPTITLE
  Value=Telescriber 2.0
  Flags=10000000
end
item: Set Variable
  Variable=GROUP
  Value=Telescriber 2.0
  Flags=10000000
end
item: Set Variable
  Variable=DISABLED
  Value=!
end
item: Set Variable
  Variable=STANDALONE
  Value=0
end
item: Parse String
  Source=%WIN%
  Pattern=:
  Variable1=SYSDRIVE
end
item: Set Variable
  Variable=MAINDIR
  Value=Telescriber 2.0
  Flags=10000000
end
item: Remark
end
item: Check Configuration
  Flags=10111011
end
item: Get Registry Key Value
  Variable=COMMON
  Key=SOFTWARE\Microsoft\Windows\CurrentVersion
  Default=%SYSDRIVE%:\Program Files\Common Files
  Value Name=CommonFilesDir
  Flags=00000100
end
item: Get Registry Key Value
  Variable=PROGRAM_FILES
  Key=SOFTWARE\Microsoft\Windows\CurrentVersion
  Default=%SYSDRIVE%:\Program Files
  Value Name=ProgramFilesDir
  Flags=00000100
end
item: Set Variable
  Variable=MAINDIR
  Value=%PROGRAM_FILES%\%MAINDIR%
  Flags=00001100
end
item: Set Variable
  Variable=EXPLORER
  Value=1
end
item: Else Statement
end
item: Set Variable
  Variable=MAINDIR
  Value=%SYSDRIVE%:\%MAINDIR%
  Flags=00001100
end
item: End Block
end
item: Remark
end
item: Set Variable
  Variable=BACKUP
  Value=%MAINDIR%\BACKUP
  Flags=10000000
end
item: Set Variable
  Variable=DOBACKUP
  Value=B
  Flags=10000000
end
item: Set Variable
  Variable=COMPONENTS
  Flags=10000000
end
item: Set Variable
  Variable=BRANDING
  Value=0
end
item: Remark
end
item: If/While Statement
  Variable=BRANDING
  Value=1
end
item: Read INI Value
  Variable=NAME
  Pathname=%INST%\CUSTDATA.INI
  Section=REGISTRATION
  Item=NAME
end
item: Read INI Value
  Variable=COMPANY
  Pathname=%INST%\CUSTDATA.INI
  Section=REGISTRATION
  Item=COMPANY
end
item: If/While Statement
  Variable=NAME
end
item: Set Variable
  Variable=DOBRAND
  Value=1
end
item: End Block
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Checking if Dialogic Service is Installed in the machine
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Get Registry Key Value
  Variable=DIALOGIC
  Key=SOFTWARE\Dialogic
  Default=0
  Value Name=Release
  Flags=00000100
end
item: If/While Statement
  Variable=DIALOGIC
  Value=SR5.1
  Flags=00001000
end
item: If/While Statement
  Variable=DIALOGIC
  Value=0
end
item: Custom Dialog Set
  Name=Dialogic Message1
  item: Dialog
    Title English=Telescriber 2.0 Installer
    Width=260
    Height=120
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Push Button
      Rectangle=103 72 152 87
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=75 22 236 37
      Create Flags=01010000000000000000000000000000
      Text English=Dialogic Software System Release 5.1 not installed.
    end
    item: Static
      Rectangle=75 45 183 61
      Create Flags=01010000000000000000000000000000
      Text English=Installation will not continue.
    end
  end
end
item: Else Statement
end
item: Custom Dialog Set
  Name=Dialogic Message2
  item: Dialog
    Title English=Telescriber 2.0 Installer
    Width=260
    Height=120
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Push Button
      Rectangle=103 72 152 87
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=75 22 226 37
      Create Flags=01010000000000000000000000000000
      Text English=Dialogic Software System Release 5.1 is required for Telescriber 2.0
    end
    item: Static
      Rectangle=75 45 183 61
      Create Flags=01010000000000000000000000000000
      Text English=Installation will not continue.
    end
  end
end
item: End Block
end
item: Delete File
  Pathname=%MAINDIR%\*
  Flags=00000100
end
item: Exit Installation
end
item: End Block
end
item: Remark
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Setting the buid number
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Set Variable
  Variable=THISBUILD
  Value=03061314
end
item: Get Registry Key Value
  Variable=BUILD
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=BuildVersion
  Flags=00000100
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Checking if a newer version is installed
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: If/While Statement
  Variable=BUILD
  Value=%THISBUILD%
  Flags=00000110
end
item: Custom Dialog Set
  Name=Telescriber Service
  item: Dialog
    Title English=Telescriber 2.0 Installer
    Width=260
    Height=138
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=70 15 242 40
      Create Flags=01010000000000000000000000000000
      Text English=A newer Build Version : %BUILD% is already installed in this system.
    end
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Static
      Rectangle=68 51 225 84
      Create Flags=01010000000000000000000000000000
      Text English= Do you want to replace it with this older Build Version : %THISBUILD%?
    end
    item: Push Button
      Rectangle=146 90 195 105
      Variable=BUILDYES
      Value=0
      Create Flags=01010000000000010000000000000000
      Text English=No
    end
    item: Push Button
      Rectangle=70 89 119 104
      Variable=BUILDYES
      Value=1
      Create Flags=01010000000000010000000000000000
      Text English=Yes
    end
  end
end
item: If/While Statement
  Variable=BUILDYES
  Value=0
end
item: Delete File
  Pathname=%MAINDIR%\*
  Flags=00000100
end
item: Exit Installation
end
item: End Block
end
item: End Block
end
item: Get Registry Key Value
  Variable=WNTVER
  Key=SOFTWARE\Microsoft\Windows NT\CurrentVersion
  Default=0
  Value Name=CurrentVersion
  Flags=00000100
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installer initialisation dialogs
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Wizard Block
  Direction Variable=DIRECTION
  Display Variable=DISPLAY
  Bitmap Pathname=%_SMSINSTL_%\DIALOGS\TEMPLATE\WIZARD.BMP
  X Position=9
  Y Position=10
  Filler Color=8421440
  Dialog=Select Program Manager Group
  Dialog=Select Backup Directory
  Dialog=Display Registration Information
  Dialog=Get Registration Information
  Variable=EXPLORER
  Variable=DOBACKUP
  Variable=DOBRAND
  Variable=DOBRAND
  Value=1
  Value=A
  Value=1
  Value=1
  Compare=0
  Compare=1
  Compare=0
  Compare=1
  Flags=00000011
end
item: Custom Dialog Set
  Name=Welcome
  Display Variable=DISPLAY
  item: Dialog
    Title Danish=%APPTITLE% Installation
    Title Dutch=Installatie van %APPTITLE%
    Title English=%APPTITLE% Installation
    Title Finnish=Asennus: %APPTITLE%
    Title French=Installation de %APPTITLE%
    Title German=Installation von %APPTITLE%
    Title Italian=Installazione di %APPTITLE%
    Title Norwegian=Installere %APPTITLE%
    Title Portuguese=Instalação de %APPTITLE%
    Title Spanish=Instalación de %APPTITLE%
    Title Swedish=Installation av %APPTITLE%
    Width=271
    Height=224
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=86 8 258 42
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text Danish=Velkommen!
      Text Dutch=Welkom!
      Text English=Welcome!
      Text Finnish=Tervetuloa
      Text French=Bienvenue !
      Text German=Willkommen!
      Text Italian=Benvenuti
      Text Norwegian=Velkommen!
      Text Portuguese=Bem-vindo!
      Text Spanish=Bienvenido
      Text Swedish=Välkommen!
    end
    item: Push Button
      Rectangle=150 187 195 202
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text Danish=&Næste >
      Text Dutch=&Volgende >
      Text English=&Next >
      Text Finnish=&Seuraava >
      Text French=&Suivant >
      Text German=&Weiter >
      Text Italian=&Avanti >
      Text Norwegian=&Neste >
      Text Portuguese=&Seguinte >
      Text Spanish=&Siguiente >
      Text Swedish= &Nästa >
    end
    item: Push Button
      Rectangle=105 187 150 202
      Variable=DISABLED
      Value=!
      Create Flags=01010000000000010000000000000000
      Text Danish=< &Tilbage
      Text Dutch=< &Terug
      Text English=< &Back
      Text Finnish=< &Edellinen
      Text French=< &Précédent
      Text German=< &Zurück
      Text Italian=< &Indietro
      Text Norwegian=< &Tilbake
      Text Portuguese=< &Anterior
      Text Spanish=< &Atrás
      Text Swedish=< &Föregående
    end
    item: Push Button
      Rectangle=211 187 256 202
      Action=3
      Create Flags=01010000000000010000000000000000
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
    item: Static
      Rectangle=86 42 256 131
      Create Flags=01010000000000000000000000000000
      Text Danish=Dette installationsprogram vil installere %APPTITLE%.
      Text Danish=
      Text Danish=Tryk på Næste for at starte installationen. Du kan trykke på Annuller, hvis du ikke vil installere %APPTITLE% nu.
      Text Dutch=Met dit installatieprogramma wordt %APPTITLE% geïnstalleerd.
      Text Dutch=
      Text Dutch=Kies de knop Volgende om de installatie te starten. Kies Annuleren als u %APPTITLE% nu niet wilt installeren.
      Text English=This installation program will install %APPTITLE%.
      Text English=
      Text English=Press the Next button to start the installation. You can press the Cancel button now if you do not want to install %APPTITLE% at this time.
      Text Finnish=Tämä asennusohjelma asentaa kohteen %APPTITLE%.
      Text Finnish=
      Text Finnish=Aloita asennus valitsemalla Seuraava. Voit valita Peruuta, jos et halua asentaa kohdetta  %APPTITLE% nyt.
      Text French=Ce programme d'installation va installer %APPTITLE%.
      Text French=
      Text French=Cliquez sur le bouton Suivant pour démarrer l'installation. Vous pouvez cliquer sur le bouton Annuler maintenant si vous ne voulez pas installer %APPTITLE% dès à présent.
      Text German=Mit diesem Installationsprogramm wird %APPTITLE% installiert.
      Text German=
      Text German=Klicken Sie auf "Weiter", um mit der Installation zu beginnen. Klicken Sie auf "Abbrechen", um die Installation von %APPTITLE% abzubrechen.
      Text Italian=Verrà installato %APPTITLE%.
      Text Italian=
      Text Italian=Per avviare l'installazione fare clic sul pulsante Avanti. Se non si desidera installare %APPTITLE% ora, scegliere Annulla.
      Text Norwegian=Dette installasjonsprogrammet installerer %APPTITLE%.
      Text Norwegian=
      Text Norwegian=Velg Neste for å starte installasjonen. Velg Avbryt hvis du ikke vil installere %APPTITLE% nå.
      Text Portuguese=Este programa de instalação instalará %APPTITLE%.
      Text Portuguese=
      Text Portuguese=Prima o botão 'Seguinte' para iniciar a instalação. Pode premir o botão 'Cancelar' agora se não desejar instalar %APPTITLE% neste momento.
      Text Spanish=Este programa de instalación instalará %APPTITLE%.
      Text Spanish=
      Text Spanish=Elija Siguiente para iniciar la instalación. Elija Cancelar si no desea instalar %APPTITLE% en este momento.
      Text Swedish=Det här installationsprogrammet kommer att installera %APPTITLE%.
      Text Swedish=
      Text Swedish=Klicka på Nästa för att påbörja installationen eller klicka på Bakåt för att skriva om installationsinformationen.
    end
    item: Static
      Rectangle=8 180 256 181
      Action=3
      Create Flags=01010000000000000000000000000111
    end
  end
end
item: Custom Dialog Set
  Name=Select Destination Directory
  Display Variable=DISPLAY
  item: Dialog
    Title Danish=%APPTITLE% Installation
    Title Dutch=Installatie van %APPTITLE%
    Title English=%APPTITLE% Installation
    Title Finnish=Asennus: %APPTITLE%
    Title French=Installation de %APPTITLE%
    Title German=Installation von %APPTITLE%
    Title Italian=Installazione di %APPTITLE%
    Title Norwegian=Installere %APPTITLE%
    Title Portuguese=Instalação de %APPTITLE%
    Title Spanish=Instalación de %APPTITLE%
    Title Swedish=Installation av %APPTITLE%
    Width=271
    Height=224
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=150 187 195 202
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text Danish=&Næste >
      Text Dutch=&Volgende >
      Text English=&Next >
      Text Finnish=&Seuraava >
      Text French=&Suivant >
      Text German=&Weiter >
      Text Italian=&Avanti >
      Text Norwegian=&Neste >
      Text Portuguese=&Seguinte >
      Text Spanish=&Siguiente >
      Text Swedish= &Nästa >
    end
    item: Push Button
      Rectangle=105 187 150 202
      Variable=DIRECTION
      Value=B
      Create Flags=01010000000000010000000000000000
      Flags=0000000000000001
      Text Danish=< &Tilbage
      Text Dutch=< &Terug
      Text English=< &Back
      Text Finnish=< &Edellinen
      Text French=< &Précédent
      Text German=< &Zurück
      Text Italian=< &Indietro
      Text Norwegian=< &Tilbake
      Text Portuguese=< &Anterior
      Text Spanish=< &Atrás
      Text Swedish=< &Föregående
    end
    item: Push Button
      Rectangle=211 187 256 202
      Action=3
      Create Flags=01010000000000010000000000000000
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
    item: Static
      Rectangle=8 180 256 181
      Action=3
      Create Flags=01010000000000000000000000000111
    end
    item: Static
      Rectangle=86 8 258 42
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text Danish=Vælg destinationsmappe
      Text Dutch=Doelmap selecteren
      Text English=Select Destination Directory
      Text Finnish=Valitse kohdekansio
      Text French=Sélectionner un répertoire de destination 
      Text German=Zielverzeichnis wählen
      Text Italian=Selezionare la directory di destinazione
      Text Norwegian=Velg målkatalog
      Text Portuguese=Seleccione o directório de destino
      Text Spanish=Seleccione el directorio de destino
      Text Swedish=Markera målkatalog
    end
    item: Static
      Rectangle=85 41 255 113
      Create Flags=01010000000000000000000000000000
      Text Danish=Vælg den mappe, som %APPTITLE%-filerne skal installeres i.
      Text Danish=
      Text Danish="Ledig diskplads efter installation'" er baseret på det aktuelle valg af filer, der skal installeres. Et negativt tal betyder, at der ikke er nok ledig diskplads til at installere programmet på det angivne drev.
      Text Dutch=Selecteer de map waarin de bestanden voor %APPTITLE% geïnstalleerd dienen te worden.
      Text Dutch=
      Text Dutch=Het getal voor "Beschikbare schijfruimte na installatie" is gebaseerd op de bestanden die u momenteel voor installatie hebt geselecteerd. Een negatief getal betekent dat er onvoldoende schijfruimte aanwezig is om de toepassing te installeren op het opgegeven station.
      Text English=Please select the directory where %APPTITLE% files are to be installed. 
      Text English=
      Text English="Free Disk Space After Install'" is based on your current selection of files to install.  A negative number indicates that there is not enough disk space to install the application to the specified drive.
      Text Finnish=Valitse kansio, johon %APPTITLE% -tiedostot asennetaan.
      Text Finnish=
      Text Finnish="Vapaa levytila asennuksen jälkeen" perustuu nykyiseen asennettavien tiedostojen valintaan. Negatiivinen arvo osoittaa, ettei valitussa asemassa ole tarpeeksi tilaa valitun ohjelman asentamiseen.
      Text French=Sélectionnez le répertoire dans lequel les fichiers de %APPTITLE% doivent être installés.
      Text French=
      Text French=L'espace disque disponible après l'installation dépend de la sélection actuelle de fichiers à installer. Un nombre négatif indique que l'espace disque n'est pas suffisant pour installer l'application sur le lecteur spécifié.
      Text German=Geben Sie an, in welchem Verzeichnis die %APPTITLE%-Dateien installiert werden sollen.
      Text German=
      Text German="Freier Speicherplatz nach der Installation" bezieht sich auf die aktuelle Auswahl an Dateien. Eine negative Zahl gibt an, dass es nicht genug Speicher auf dem angegebenen Laufwerk gibt, um die Anwendung dort zu installieren.
      Text Italian=Selezionare la directory in cui verranno installati i file %APPTITLE%.
      Text Italian=
      Text Italian=Il valore di "Spazio disponibile su disco dopo l'installazione" è calcolato in base ai file selezionati per l'installazione. Un valore negativo indica che lo spazio disponibile sull'unità specificata non è sufficiente per l'installazione dell'applicazione.
      Text Norwegian=Velg hvilken katalog %APPTITLE%-filene skal installeres i.
      Text Norwegian=
      Text Norwegian="Ledig diskplass etter installasjon" baseres på hvilke filer du har valgt å installere. Et negativt tall betyr at det ikke er nok diskplass til å installere programmet på angitt stasjon.
      Text Portuguese=Seleccione o directório onde serão instalados os ficheiros de %APPTITLE%.
      Text Portuguese=
      Text Portuguese="Espaço livre em disco depois da instalação'" é baseado na selecção actual de ficheiros a instalar.  Um número negativo indica que não existe espaço suficiente para instalar a aplicação na unidade indicada.
      Text Spanish=Seleccione el directorio donde desee instalar los archivos de %APPTITLE%.
      Text Spanish=
      Text Spanish="Espacio después de instalar'" tiene en cuenta la selección actual de archivos que desea instalar.  Un número negativo indica que no hay suficiente espacio en disco para instalar la aplicación en la unidad especificada.
      Text Swedish=Markera katalogen där %APPTITLE%-filerna ska installeras.
      Text Swedish=
      Text Swedish="Ledigt diskutrymme efter installation" baseras på vilka filer som är markerade för installation. Ett negativt tal innebär att det inte finns tillräckligt med diskutrymme för att installera programmet på angiven enhet.
    end
    item: Static
      Rectangle=86 110 256 137
      Action=1
      Create Flags=01010000000000000000000000000111
    end
    item: Push Button
      Rectangle=208 118 253 133
      Variable=MAINDIR_SAVE
      Value=%MAINDIR%
      Destination Dialog=1
      Action=2
      Create Flags=01010000000000010000000000000000
      Text Danish=&Gennemse...
      Text Dutch=B&laderen...
      Text English=B&rowse...
      Text Finnish=S&elaa...
      Text French=Parco&urir...
      Text German=Durchsuchen...
      Text Italian=&Sfoglia
      Text Norwegian=&Bla gjennom...
      Text Portuguese=P&rocurar...
      Text Spanish=E&xaminar...
      Text Swedish= B&läddra...
    end
    item: Static
      Rectangle=90 121 206 132
      Destination Dialog=2
      Create Flags=01010000000000000000000000000000
      Text Danish=%MAINDIR%
      Text Dutch=%MAINDIR%
      Text English=%MAINDIR%
      Text Finnish=%MAINDIR%
      Text French=%MAINDIR%
      Text German=%MAINDIR%
      Text Italian=%MAINDIR%
      Text Norwegian=%MAINDIR%
      Text Portuguese=%MAINDIR%
      Text Spanish=%MAINDIR%
      Text Swedish=%MAINDIR% 
    end
    item: Static
      Rectangle=203 158 251 168
      Variable=COMPONENTS
      Value=MAINDIR
      Create Flags=01010000000000000000000000000010
    end
    item: Static
      Rectangle=203 148 251 157
      Value=MAINDIR
      Create Flags=01010000000000000000000000000010
    end
    item: Static
      Rectangle=90 148 190 159
      Create Flags=01010000000000000000000000000000
      Text Danish=Nuværende ledig diskplads:
      Text Dutch=Beschikbare schijfruimte:
      Text English=Current Free Disk Space:
      Text Finnish=Nykyinen vapaa levytila:
      Text French=Espace disque disponible actuel :
      Text German=Freier Speicherplatz:
      Text Italian=Spazio disponibile su disco:
      Text Norwegian=Ledig diskplass:
      Text Portuguese=Espaço livre em disco:
      Text Spanish=Espacio en disco actual:
      Text Swedish=Ledigt diskutrymme:
    end
    item: Static
      Rectangle=90 158 216 168
      Create Flags=01010000000000000000000000000000
      Text Danish=Ledig diskplads efter installation:
      Text Dutch=Beschikbare schijfruimte na installatie:
      Text English=Free Disk Space After Install:
      Text Finnish=Vapaa levytila asennuksen jälkeen:
      Text French=Espace disque disponible après l'installation :
      Text German=Freier Speicherplatz nach der Installation:
      Text Italian=Spazio disponibile su disco dopo l'installazione:
      Text Norwegian=Ledig diskplass etter installasjon:
      Text Portuguese=Espaço livre em disco depois da instalação:
      Text Spanish=Espacio después de instalar:
      Text Swedish=Ledigt diskutrymme efter installation:
    end
    item: Static
      Rectangle=86 140 256 170
      Action=1
      Create Flags=01010000000000000000000000000111
    end
  end
  item: Dialog
    Title Danish=Vælg destinationsmappe
    Title Dutch=Doelmap selecteren
    Title English=Select Destination Directory
    Title Finnish=Valitse kohdekansio
    Title French=Sélectionner un répertoire de destination 
    Title German=Zielverzeichnis wählen
    Title Italian=Selezionare la directory di destinazione
    Title Norwegian=Velg målkatalog
    Title Portuguese=Seleccione o directório de destino
    Title Spanish=Seleccione el directorio de destino
    Title Swedish=Markera målkatalog
    Width=221
    Height=173
    Font Name=Helv
    Font Size=8
    item: Listbox
      Rectangle=5 5 163 149
      Variable=MAINDIR_SAVE
      Create Flags=01010000100000010000000101000000
      Flags=0000110000100010
      Text Danish=%MAINDIR%
      Text Dutch=%MAINDIR%
      Text English=%MAINDIR%
      Text Finnish=%MAINDIR%
      Text French=%MAINDIR%
      Text German=%MAINDIR%
      Text Italian=%MAINDIR%
      Text Norwegian=%MAINDIR%
      Text Portuguese=%MAINDIR%
      Text Spanish=%MAINDIR%
      Text Swedish=%MAINDIR%
    end
    item: Push Button
      Rectangle=167 6 212 21
      Variable=MAINDIR
      Value=%MAINDIR_SAVE%
      Create Flags=01010000000000010000000000000001
      Text Danish=OK
      Text Dutch=OK
      Text English=OK
      Text Finnish=OK
      Text French=OK
      Text German=OK
      Text Italian=OK
      Text Norwegian=OK
      Text Portuguese=OK
      Text Spanish=Aceptar
      Text Swedish=OK
    end
    item: Push Button
      Rectangle=167 25 212 40
      Create Flags=01010000000000010000000000000000
      Flags=0000000000000001
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
  end
end
item: Custom Dialog Set
  Name=Select Program Manager Group
  Display Variable=DISPLAY
  item: Dialog
    Title Danish=%APPTITLE% Installation
    Title Dutch=Installatie van %APPTITLE%
    Title English=%APPTITLE% Installation
    Title Finnish=Asennus: %APPTITLE%
    Title French=Installation de %APPTITLE%
    Title German=Installation von %APPTITLE%
    Title Italian=Installazione di %APPTITLE%
    Title Norwegian=Installere %APPTITLE%
    Title Portuguese=Instalação de %APPTITLE%
    Title Spanish=Instalación de %APPTITLE%
    Title Swedish=Installation av %APPTITLE%
    Width=271
    Height=224
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=150 187 195 202
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text Danish=&Næste >
      Text Dutch=&Volgende >
      Text English=&Next >
      Text Finnish=&Seuraava >
      Text French=&Suivant >
      Text German=&Weiter >
      Text Italian=&Avanti >
      Text Norwegian=&Neste >
      Text Portuguese=&Seguinte >
      Text Spanish=&Siguiente >
      Text Swedish= &Nästa >
    end
    item: Push Button
      Rectangle=105 187 150 202
      Variable=DIRECTION
      Value=B
      Create Flags=01010000000000010000000000000000
      Flags=0000000000000001
      Text Danish=< &Tilbage
      Text Dutch=< &Terug
      Text English=< &Back
      Text Finnish=< &Edellinen
      Text French=< &Précédent
      Text German=< &Zurück
      Text Italian=< &Indietro
      Text Norwegian=< &Tilbake
      Text Portuguese=< &Anterior
      Text Spanish=< &Atrás
      Text Swedish=< &Föregående
    end
    item: Push Button
      Rectangle=211 187 256 202
      Action=3
      Create Flags=01010000000000010000000000000000
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
    item: Static
      Rectangle=8 180 256 181
      Action=3
      Create Flags=01010000000000000000000000000111
    end
    item: Static
      Rectangle=86 8 258 42
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text Danish=Vælg gruppe i Programstyring
      Text Dutch=Groep in ProgMan selecteren
      Text English=Select ProgMan Group
      Text Finnish=Valitse Järjestelmänhallinnan ryhmä
      Text French=Sélectionner le groupe du Gestionnaire de programmes
      Text German=Bestimmung der Programm-Managergruppe
      Text Italian=Selezionare il gruppo di Program Manager
      Text Norwegian=Velg programbehandlingsgruppe
      Text Portuguese=Seleccione o grupo do Gestor de programas
      Text Spanish=Seleccione Grupo del Admin. prog.
      Text Swedish=Markera en grupp i Programhanteraren
    end
    item: Static
      Rectangle=86 44 256 68
      Create Flags=01010000000000000000000000000000
      Text Danish=Skriv navnet på den gruppe i Programstyring, som %APPTITLE%-ikonerne skal føjes til:
      Text Dutch=Voer de naam in van de groep in Programmabeheer waar u de pictogrammen voor %APPTITLE% aan wilt toevoegen:
      Text English=Enter the name of the Program Manager group to which to add %APPTITLE% icons:
      Text Finnish=Valitse Järjestelmänhallinnan ryhmä, johon haluat lisätä kohteen  %APPTITLE% kuvakkeet:
      Text French=Entrez le nom du groupe du Gestionnaire de programme dans lequel vous souhaitez ajouter les icônes de %APPTITLE% :
      Text German=Geben Sie den Namen der Programmgruppe ein, der das Symbol %APPTITLE% hinzugefügt werden soll:
      Text Italian=Immettere il nome del gruppo di Program Manager a cui aggiungere le icone %APPTITLE%:
      Text Norwegian=Angi navnet på programbehandlingsgruppen hvor %APPTITLE%-ikonene skal legges til:
      Text Portuguese=Escreva o nome do grupo do 'Gestor de programas' onde serão adicionados os ícones de %APPTITLE%:
      Text Spanish=Escriba el nombre del grupo del Administrador de programas al que desea agregar los iconos de %APPTITLE%:
      Text Swedish=Skriv namnet på gruppen i Programhanteraren dit du vill lägga %APPTITLE%-ikonerna:
    end
    item: Combobox
      Rectangle=86 69 256 175
      Variable=GROUP
      Create Flags=01010000001000010000001100000001
      Flags=0000000000000001
      Text Danish=%GROUP%
      Text Dutch=%GROUP%
      Text English=%GROUP%
      Text Finnish=%GROUP%
      Text French=%GROUP%
      Text German=%GROUP%
      Text Italian=%GROUP%
      Text Norwegian=%GROUP%
      Text Portuguese=%GROUP%
      Text Spanish=%GROUP%
      Text Swedish=%GROUP%
    end
  end
end
item: Custom Dialog Set
  Name=Teleinstaller
  Display Variable=DISPLAY
  item: Dialog
    Title English=%APPTITLE% Installation
    Width=271
    Height=222
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=88 10 231 47
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text English=Select Installation Type
    end
    item: Static
      Rectangle=90 46 220 61
      Create Flags=01010000000000000000000000000000
      Text English=Please specify your Installation Type.
    end
    item: Radio Button
      Rectangle=125 119 213 151
      Variable=STANDALONE
      Create Flags=01010000000000010000000000001001
      Text English=Integrated Telescriber
      Text English=Standalone Telescriber
      Text English=
    end
    item: Static
      Rectangle=9 177 257 182
      Action=1
      Create Flags=01010000000000000000000000000111
    end
    item: Push Button
      Rectangle=102 186 146 201
      Variable=DIRECTION
      Value=B
      Create Flags=01010000000000010000000000000000
      Text English=< &Back
    end
    item: Push Button
      Rectangle=146 186 190 201
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text English=&Next >
    end
    item: Push Button
      Rectangle=212 186 256 200
      Action=3
      Create Flags=01010000000000010000000000000000
      Text English=Cancel
    end
    item: Static
      Rectangle=90 63 222 80
      Create Flags=01010000000000000000000000000000
      Text English=The Standalone version works without any connection with the DataCenter.
    end
    item: Static
      Rectangle=91 87 223 104
      Create Flags=01010000000000000000000000000000
      Text English=The Integrated version works in connection with the DataCenter.
    end
  end
end
item: Custom Dialog Set
  Name=Start Installation
  Display Variable=DISPLAY
  item: Dialog
    Title Danish=%APPTITLE% Installation
    Title Dutch=Installatie van %APPTITLE%
    Title English=%APPTITLE% Installation
    Title Finnish=Asennus: %APPTITLE%
    Title French=Installation de %APPTITLE%
    Title German=Installation von %APPTITLE%
    Title Italian=Installazione di %APPTITLE%
    Title Norwegian=Installere %APPTITLE%
    Title Portuguese=Instalação de %APPTITLE%
    Title Spanish=Instalación de %APPTITLE%
    Title Swedish=Installation av %APPTITLE%
    Width=271
    Height=224
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=150 187 195 202
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text Danish=&Næste >
      Text Dutch=&Volgende >
      Text English=&Next >
      Text Finnish=&Seuraava >
      Text French=&Suivant >
      Text German=&Weiter >
      Text Italian=&Avanti >
      Text Norwegian=&Neste >
      Text Portuguese=&Seguinte >
      Text Spanish=&Siguiente >
      Text Swedish= &Nästa >
    end
    item: Push Button
      Rectangle=105 187 150 202
      Variable=DIRECTION
      Value=B
      Create Flags=01010000000000010000000000000000
      Text Danish=< &Tilbage
      Text Dutch=< &Terug
      Text English=< &Back
      Text Finnish=< &Edellinen
      Text French=< &Précédent
      Text German=< &Zurück
      Text Italian=< &Indietro
      Text Norwegian=< &Tilbake
      Text Portuguese=< &Anterior
      Text Spanish=< &Atrás
      Text Swedish=< &Föregående
    end
    item: Push Button
      Rectangle=211 187 256 202
      Action=3
      Create Flags=01010000000000010000000000000000
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
    item: Static
      Rectangle=8 180 256 181
      Action=3
      Create Flags=01010000000000000000000000000111
    end
    item: Static
      Rectangle=86 8 258 42
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text Danish=Klar til at installere!
      Text Dutch=Klaar om te installeren!
      Text English=Ready to Install!
      Text Finnish=Valmis asentamaan.
      Text French=Prêt à installer !
      Text German=Installationsbereit!
      Text Italian=Pronto per l'installazione
      Text Norwegian=Klar til å installere.
      Text Portuguese=Pronto para instalar!
      Text Spanish=Preparado para la instalación.
      Text Swedish=Klart för installation.
    end
    item: Static
      Rectangle=86 42 256 102
      Create Flags=01010000000000000000000000000000
      Text Danish=Du er nu klar til at installere %APPTITLE%.
      Text Danish=
      Text Danish=Tryk på Næste for at starte installationen, eller tryk på Tilbage for at ændre installationsoplysningerne.
      Text Dutch=%APPTITLE% kan nu geïnstalleerd worden.
      Text Dutch=
      Text Dutch=Kies de knop Volgende als u de installatie wilt starten, of kies Terug als u de installatiegegevens opnieuw wilt invoeren.
      Text English=You are now ready to install %APPTITLE%.
      Text English=
      Text English=Press the Next button to begin the installation or the Back button to re-enter the installation information.
      Text Finnish=Kohteen %APPTITLE% voi nyt asentaa.
      Text Finnish=
      Text Finnish=Aloita asennus valitsemalla Seuraava tai määritä asennustiedot uudelleen valitsemalla Edellinen.
      Text French=Vous êtes maintenant prêt à installer %APPTITLE%.
      Text French=
      Text French=Cliquez sur le bouton Suivant pour commencer l'installation ou sur le bouton Précédent pour entrer de nouveau les informations d'installation.
      Text German=Sie können %APPTITLE% nun installieren.
      Text German=
      Text German=Klicken Sie auf "Weiter", um mit der Installation zu beginnen. Klicken Sie auf "Zurück", um die Installationsinformationen neu einzugeben.
      Text Italian=Ora è possibile installare %APPTITLE%.
      Text Italian=
      Text Italian=Fare clic sul pulsante Avanti per avviare l'installazione o sul pulsante Indietro per reimmettere le informazioni sull'installazione.
      Text Norwegian=%APPTITLE% kan nå installeres.
      Text Norwegian=
      Text Norwegian=Velg Neste for å starte installasjonen, eller velgTilbake for å angi installasjonsinformasjonen på nytt.
      Text Portuguese=Está pronto para instalar %APPTITLE%.
      Text Portuguese=
      Text Portuguese=Prima o botão 'Seguinte' para iniciar a instalação ou no botão 'Anterior' para voltar a introduzir as informações de instalação.
      Text Spanish=Ya está listo para instalar %APPTITLE%.
      Text Spanish=
      Text Spanish=Elija Siguiente para iniciar la instalación o Atrás para introducir de nuevo la información para la instalación.
      Text Swedish=Du kan nu installera %APPTITLE%.
      Text Swedish=
      Text Swedish=Välj Nästa för att påbörja installationen eller klicka på Föregående om du vill skriva om installationsinformationen.
    end
  end
end
item: If/While Statement
  Variable=DISPLAY
  Value=Select Destination Directory
end
item: Set Variable
  Variable=BACKUP
  Value=%MAINDIR%\BACKUP
end
item: End Block
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Checking which version standalone or integrated versoin
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Get Registry Key Value
  Variable=GLOBALID
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=GlobalID
  Flags=00000100
end
item: If/While Statement
  Variable=GLOBALID
  Value=0
  Flags=00000001
end
item: Custom Dialog Set
  Name=Telescriber Registration
  item: Dialog
    Title English=Telescriber 2.0 Registration
    Width=269
    Height=107
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=70 16 242 24
      Create Flags=01010000000000000000000000000000
      Text English=A registration for Telescriber 2.0 is present in this system.
    end
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Static
      Rectangle=67 37 221 51
      Create Flags=01010000000000000000000000000000
      Text English= Do you want to install with a fresh registration?
    end
    item: Push Button
      Rectangle=146 64 195 79
      Variable=FRESH
      Value=0
      Create Flags=01010000000000010000000000000000
      Text English=No
    end
    item: Push Button
      Rectangle=71 64 120 79
      Variable=FRESH
      Value=1
      Create Flags=01010000000000010000000000000000
      Text English=Yes
    end
  end
end
item: If/While Statement
  Variable=FRESH
  Value=1
  Flags=00000100
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=0
  Value Name=GlobalID
  Root=2
  Data Type=3
end
item: End Block
end
item: End Block
end
item: End Block
end
item: If/While Statement
  Variable=DOBACKUP
  Value=A
end
item: Set Variable
  Variable=BACKUPDIR
  Value=%BACKUP%
end
item: End Block
end
item: If/While Statement
  Variable=BRANDING
  Value=1
end
item: If/While Statement
  Variable=DOBRAND
  Value=1
end
item: Edit INI File
  Pathname=%INST%\CUSTDATA.INI
  Settings=[REGISTRATION]
  Settings=NAME=%NAME%
  Settings=COMPANY=%COMPANY%
  Settings=
end
item: End Block
end
item: End Block
end
item: Open/Close INSTALL.LOG
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Checking if ODBC drivers are present , if not install them
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Check Disk Space
  Component=COMPONENTS
end
item: Get Registry Key Value
  Variable=ACCESSDRV
  Key=SOFTWARE\ODBC\ODBCINST.INI\Microsoft Access Driver (*.mdb)
  Default=0
  Value Name=Driver
  Flags=00000100
end
remarked item: Install File
  Source=h:\ODBCSetup.EXE
  Destination=%MAINDIR%\ODBCSetup.EXE
  Flags=0000000000000010
end
item: If/While Statement
  Variable=ACCESSDRV
  Value=0
  Flags=00000001
end
item: Check if File/Dir Exists
  Pathname=%ACCESSDRV%
  Flags=00000101
end
item: Custom Dialog Set
  Name=ODBC Message
  item: Dialog
    Title English=Telescriber 2.0 Installer
    Width=260
    Height=120
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Push Button
      Rectangle=103 73 152 88
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=75 19 236 30
      Create Flags=01010000000000000000000000000000
      Text English=Access driver is not found in this system.
    end
    item: Static
      Rectangle=74 52 233 68
      Create Flags=01010000000000000000000000000000
      Text English=Teleinstaller will now install ODBC MS Access 97 driver.
    end
    item: Static
      Rectangle=74 32 235 43
      Create Flags=01010000000000000000000000000000
      Text English=Telescriber 2.0 requires atleast a MS Access 97 driver.
    end
  end
end
item: Install ODBC Driver
  Manager Variable=MANAGER
  Driver Variable=DRIVER
  Attributes=Microsoft Access Driver (*.mdb)
  Attributes=Driver=odbcjt32.dll
  Attributes=Setup=odbcjt32.dl
  Attributes=lName=Microsoft Access Driver (*.mdb)
  Attributes=APILevel=1
  Attributes=ConnectFunctions=YYN
  Attributes=DriverODBCVer=02.50
  Attributes=FileUsage=2F
  Attributes=ileExtns=*.mdb
  Attributes=SQLLevel=0
  Attributes=ConfigDSN=DSN=MS Access 7.0 Database|UID=Admin||
  Flags=00000001
end
remarked item: Execute Program
  Pathname=%MAINDIR%\ODBCSetup.exe
  Flags=00000010
end
item: End Block
end
item: Else Statement
end
item: Custom Dialog Set
  Name=ODBC Message
  item: Dialog
    Title English=Telescriber 2.0 Installer
    Width=260
    Height=120
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=16 18 51 51
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
    item: Push Button
      Rectangle=103 73 152 88
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=75 19 236 30
      Create Flags=01010000000000000000000000000000
      Text English=Access driver is not found in this system.
    end
    item: Static
      Rectangle=74 52 233 68
      Create Flags=01010000000000000000000000000000
      Text English=Teleinstaller will now install ODBC MS Access 97 driver.
    end
    item: Static
      Rectangle=74 32 235 43
      Create Flags=01010000000000000000000000000000
      Text English=Telescriber 2.0 requires atleast a MS Access 97 driver.
    end
  end
end
item: Install ODBC Driver
  Manager Variable=MANAGER
  Driver Variable=DRIVER
  Attributes=Microsoft Access Driver (*.mdb)
  Attributes=Driver=odbcjt32.dll
  Attributes=Setup=odbcjt32.dl
  Attributes=lName=Microsoft Access Driver (*.mdb)
  Attributes=APILevel=1
  Attributes=ConnectFunctions=YYN
  Attributes=DriverODBCVer=02.50
  Attributes=FileUsage=2F
  Attributes=ileExtns=*.mdb
  Attributes=SQLLevel=0
  Attributes=ConfigDSN=DSN=MS Access 7.0 Database|UID=Admin||
  Flags=00000001
end
remarked item: Execute Program
  Pathname=%MAINDIR%\ODBCSetup.exe
  Flags=00000010
end
item: Delete File
  Pathname=%MAINDIR%\ODBCSetup.exe
end
item: End Block
end
remarked item: Delete File
  Pathname=%MAINDIR%\ODBCSetup.exe
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing Core application components
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Install File
  Source=H:\TELECUSTOM SETUP\Summerlin\TeleCustom.dll
  Destination=%MAINDIR%\TeleCustom.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\TELECUSTOM SETUP\MyIVR1.exe
  Destination=%MAINDIR%\MyIVR1.exe
  Flags=0000000000000010
end
item: Install File
  Source=H:\TELECUSTOM SETUP\TDS_chart.exe
  Destination=%MAINDIR%\TDS_chart.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\TELECUSTOM SETUP\Application.xml
  Destination=%MAINDIR%\Application.xml
  Flags=0000000000000010
end
item: Install File
  Source=H:\TELECUSTOM SETUP\Summerlin\TeleCustom.xml
  Destination=%MAINDIR%\Application\Backup\TeleCustom.xml
  Flags=0000000000000010
end
item: Install File
  Source=H:\TELECUSTOM SETUP\Summerlin\TeleCustom.xml
  Destination=%MAINDIR%\Application\TeleCustom.xml
  Flags=0000000000000010
end
item: Install File
  Source=h:\SMA SetUp\MapTemplate.xml
  Destination=%MAINDIR%\MapTemplate.xml
  Flags=0000000000000010
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=To add transactor service
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Install File
  Source=H:\SMA SetUp\TransTrayService.exe
  Destination=%MAINDIR%\TransTrayService.exe
  Flags=0000000000000010
end
item: Install File
  Source=H:\SMA SetUp\ServiceTool.exe
  Destination=%MAINDIR%\ServiceTool.exe
  Flags=0000000000000010
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Install File
  Source=H:\SMA SetUp\DoctorRegComForTelescriber.ocx
  Destination=%MAINDIR%\DoctorRegComForTelescriber.ocx
  Flags=0001000000000010
end
item: Else Statement
end
item: Install File
  Source=H:\DoctorRegComForSATelescriber.ocx
  Destination=%MAINDIR%\DoctorRegComForSATelescriber.ocx
  Flags=0001000000000010
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing Other Application files and dlls
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Install File
  Source=h:\TDSInstallSA.exe
  Destination=%MAINDIR%\TDSInstallSA.exe
  Flags=0000000000000010
end
item: Install File
  Source=H:\ASUS_Update Setup\TelescriberAdmin.exe
  Destination=%MAINDIR%\TelescriberAdmin.exe
  Flags=0000000000000010
end
item: Install File
  Source=H:\TelescriberAdmin.xml
  Destination=%MAINDIR%\TelescriberAdmin.xml
  Flags=0000000000000010
end
item: Install File
  Source=h:\ClientReg.exe
  Destination=%MAINDIR%\ClientReg.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\UserInfo.xml
  Destination=%MAINDIR%\UserInfo.xml
  Flags=0000000000000010
end
item: Install File
  Source=h:\TransFile.tlb
  Destination=%MAINDIR%\TransFile.tlb
  Flags=0000000000000010
end
item: Install File
  Source=h:\TransFile.dll
  Destination=%MAINDIR%\TransFile.dll
  Flags=0001000000000010
end
item: Remark
end
item: Install File
  Source=h:\Templates.xml
  Destination=%MAINDIR%\Templates.xml
  Flags=0000000000000010
end
item: Install File
  Source=h:\TelescriberSvc.exe
  Destination=%MAINDIR%\TelescriberSvc.exe
  Flags=0000000000000010
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Install File
  Source=H:\Telescriber Settings.exe
  Destination=%MAINDIR%\Telescriber Settings.exe
  Flags=0000000000000010
end
item: Else Statement
end
item: Install File
  Source=H:\Telescriber Settings_SA.exe
  Destination=%MAINDIR%\Telescriber Settings.exe
  Flags=0000000000000010
end
item: End Block
end
item: Install File
  Source=H:\SMA SetUp\TDSInstall.exe
  Destination=%MAINDIR%\TDSInstall.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\StartUpdation.exe
  Destination=%MAINDIR%\StartUpdation.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\QWReportWord.doc
  Destination=%MAINDIR%\QWReportWord.doc
  Flags=0000000000000010
end
item: Install File
  Source=h:\Query.txt
  Destination=%MAINDIR%\Query.txt
  Flags=0000000000000010
end
item: Install File
  Source=H:\InstallInit.exe
  Destination=%MAINDIR%\InstallInit.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\implode.dll
  Destination=%MAINDIR%\implode.dll
  Flags=0000000000000010
end
item: Install File
  Source=h:\GSMConverter.dll
  Destination=%MAINDIR%\GSMConverter.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\GenerateReportCOM.tlb
  Destination=%MAINDIR%\GenerateReportCOM.tlb
  Flags=0000000000000010
end
item: Install File
  Source=h:\GenerateReportCOM.dll
  Destination=%MAINDIR%\GenerateReportCOM.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\DoctorRegExtnForTelescriber.tlb
  Destination=%MAINDIR%\DoctorRegExtnForTelescriber.tlb
  Flags=0000000000000010
end
item: Install File
  Source=h:\DoctorRegExtnForTelescriber.dll
  Destination=%MAINDIR%\DoctorRegExtnForTelescriber.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\Doctor Registration.exe
  Destination=%MAINDIR%\Doctor Registration.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\crpe32.dll
  Destination=%MAINDIR%\crpe32.dll
  Flags=0000000000000010
end
item: Install File
  Source=h:\Co2c40en.dll
  Destination=%MAINDIR%\Co2c40en.dll
  Flags=0000000000000010
end
item: Install File
  Source=H:\ClientInstallCOM_ASUS.dll
  Destination=%MAINDIR%\ClientInstallCOM.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\ClientInfo.exe
  Destination=%MAINDIR%\ClientInfo.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\channels.xml
  Destination=%MAINDIR%\channels.xml
  Flags=0000000000000010
end
item: Install File
  Source=h:\ChannelDisconnectCOM.tlb
  Destination=%MAINDIR%\ChannelDisconnectCOM.tlb
  Flags=0000000000000010
end
item: Install File
  Source=h:\ChannelDisconnectCOM.dll
  Destination=%MAINDIR%\ChannelDisconnectCOM.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\ChangeWave.exe
  Destination=%MAINDIR%\ChangeWave.exe
  Flags=0000000000000010
end
item: Install File
  Source=h:\aussettings.xml
  Destination=%MAINDIR%\aussettings.xml
  Flags=0000000000000010
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing the Telscriber databse after asking if the user needs to replace it
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Open/Close INSTALL.LOG
  Flags=00000001
end
breakpoint item: Check if File/Dir Exists
  Pathname=%MAINDIR%\Telescriber.mdb
  Title English=Telescriber 2.0 Installation
  Flags=00000100
end
item: Custom Dialog Set
  Name=Telescriber 2.0 Installation
  item: Dialog
    Title English=Telescriber 2.0 Installation
    Width=173
    Height=75
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=18 10 161 29
      Create Flags=01010000000000000000000000000000
      Text English=The Database file Telescriber.mdb already exists.
      Text English=Do you want to replace the file?
    end
    item: Push Button
      Rectangle=33 34 68 49
      Variable=DATAREP
      Value=1
      Create Flags=01010000000000010000000000000000
      Text English=Yes
    end
    item: Push Button
      Rectangle=90 34 125 49
      Variable=DATAREP
      Value=0
      Create Flags=01010000000000010000000000000000
      Text English=No
    end
  end
end
item: If/While Statement
  Variable=DATAREP
  Value=1
end
item: Delete File
  Pathname=%MAINDIR%\Telescriber.mdb
end
item: Install File
  Source=H:\SMA SetUp\Telescriber.mdb
  Destination=%MAINDIR%\Telescriber.mdb
  Flags=0000000000000010
end
item: End Block
end
item: Else Statement
end
item: Install File
  Source=H:\SMA SetUp\Telescriber.mdb
  Destination=%MAINDIR%\Telescriber.mdb
  Flags=0000000000000010
end
item: End Block
end
item: Open/Close INSTALL.LOG
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Registry entries to create DSN
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Win32 System Directory
  Variable=WIN32DIR
end
item: Edit Registry
  Total Keys=7
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    New Value=%MAINDIR%\Telescriber.mdb
    Value Name=DBQ
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    New Value=%WIN32DIR%\odbcjt32.dll
    Value Name=Driver
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    New Value=25
    Value Name=DriverId
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    New Value=MS Access;
    Value Name=FIL
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    New Value=0
    Value Name=SafeTransactions
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\Telescriber
    Value Name=UID
    Root=2
  end
  item: Key
    Key=SOFTWARE\ODBC\ODBC.INI\ODBC Data Sources
    New Value=Microsoft Access Driver (*.mdb)
    Value Name=Telescriber
    Root=2
  end
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing the required wave files
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Install File
  Source=h:\Waves\TeleCustom\worktype.wav
  Destination=%MAINDIR%\Waves\TeleCustom\worktype.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\welcome.wav
  Destination=%MAINDIR%\Waves\TeleCustom\welcome.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\VisitNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\VisitNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\UserID.wav
  Destination=%MAINDIR%\Waves\TeleCustom\UserID.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\TurnAround.wav
  Destination=%MAINDIR%\Waves\TeleCustom\TurnAround.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\TryLater.wav
  Destination=%MAINDIR%\Waves\TeleCustom\TryLater.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\TryAgain.wav
  Destination=%MAINDIR%\Waves\TeleCustom\TryAgain.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\TrackNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\TrackNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\SystemReady.wav
  Destination=%MAINDIR%\Waves\TeleCustom\SystemReady.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\StopRevOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\StopRevOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\StopRecOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\StopRecOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\StopOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\StopOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\saveas.wav
  Destination=%MAINDIR%\Waves\TeleCustom\saveas.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RevStop.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RevStop.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RevPause.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RevPause.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RevOptions2.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RevOptions2.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RevOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RevOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RevContinue.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RevContinue.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecStop.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecStop.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecSend.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecSend.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecPause.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecPause.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecordNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecordNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecContinue.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecContinue.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\RecCancel.wav
  Destination=%MAINDIR%\Waves\TeleCustom\RecCancel.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\QuickRev.wav
  Destination=%MAINDIR%\Waves\TeleCustom\QuickRev.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\PleaseWait.wav
  Destination=%MAINDIR%\Waves\TeleCustom\PleaseWait.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\PendOptions.wav
  Destination=%MAINDIR%\Waves\TeleCustom\PendOptions.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\PendFile.wav
  Destination=%MAINDIR%\Waves\TeleCustom\PendFile.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\PatientID.wav
  Destination=%MAINDIR%\Waves\TeleCustom\PatientID.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\NotSent.wav
  Destination=%MAINDIR%\Waves\TeleCustom\NotSent.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\NotConfirmed.wav
  Destination=%MAINDIR%\Waves\TeleCustom\NotConfirmed.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\NoPrev.wav
  Destination=%MAINDIR%\Waves\TeleCustom\NoPrev.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\NoNext.wav
  Destination=%MAINDIR%\Waves\TeleCustom\NoNext.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\NoMatching.wav
  Destination=%MAINDIR%\Waves\TeleCustom\NoMatching.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\menu.wav
  Destination=%MAINDIR%\Waves\TeleCustom\menu.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Marked.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Marked.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\MainMenu.wav
  Destination=%MAINDIR%\Waves\TeleCustom\MainMenu.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\InvalidFile.wav
  Destination=%MAINDIR%\Waves\TeleCustom\InvalidFile.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Invalid.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Invalid.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\hangingup.wav
  Destination=%MAINDIR%\Waves\TeleCustom\hangingup.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\FreshFile.wav
  Destination=%MAINDIR%\Waves\TeleCustom\FreshFile.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Forwarded.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Forwarded.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\FileSent.wav
  Destination=%MAINDIR%\Waves\TeleCustom\FileSent.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\FileSave.wav
  Destination=%MAINDIR%\Waves\TeleCustom\FileSave.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EOF.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EOF.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterTrackNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterTrackNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterTemplate.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterTemplate.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterSiteNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterSiteNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterPassword.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterPassword.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterNumber.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterNumber.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterNo.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterNo.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterID.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterID.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\EnterChar.wav
  Destination=%MAINDIR%\Waves\TeleCustom\EnterChar.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\disMenu.wav
  Destination=%MAINDIR%\Waves\TeleCustom\disMenu.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Disconnect.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Disconnect.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\CantReview.wav
  Destination=%MAINDIR%\Waves\TeleCustom\CantReview.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Cancelled.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Cancelled.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\Blank.wav
  Destination=%MAINDIR%\Waves\TeleCustom\Blank.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\BegOfFile.wav
  Destination=%MAINDIR%\Waves\TeleCustom\BegOfFile.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\AccountInUse.wav
  Destination=%MAINDIR%\Waves\TeleCustom\AccountInUse.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\9.wav
  Destination=%MAINDIR%\Waves\TeleCustom\9.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\9!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\9!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\8.wav
  Destination=%MAINDIR%\Waves\TeleCustom\8.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\8!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\8!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\7.wav
  Destination=%MAINDIR%\Waves\TeleCustom\7.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\7!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\7!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\6.wav
  Destination=%MAINDIR%\Waves\TeleCustom\6.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\6!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\6!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\5.wav
  Destination=%MAINDIR%\Waves\TeleCustom\5.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\5!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\5!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\4.wav
  Destination=%MAINDIR%\Waves\TeleCustom\4.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\4!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\4!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\3_rvw1_rec.wav
  Destination=%MAINDIR%\Waves\TeleCustom\3_rvw1_rec.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\3.wav
  Destination=%MAINDIR%\Waves\TeleCustom\3.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\3!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\3!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\0!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\0!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\0.wav
  Destination=%MAINDIR%\Waves\TeleCustom\0.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\1!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\1!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\1.wav
  Destination=%MAINDIR%\Waves\TeleCustom\1.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\2!.wav
  Destination=%MAINDIR%\Waves\TeleCustom\2!.wav
  Flags=0000000000000010
end
item: Install File
  Source=h:\Waves\TeleCustom\2.wav
  Destination=%MAINDIR%\Waves\TeleCustom\2.wav
  Flags=0000000000000010
end
item: Remark
end
item: Include Script
  Pathname=h:\\Uninstal.ipf
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=We dont want to uninstall common files
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Open/Close INSTALL.LOG
  Flags=00000001
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=To get common folder files
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Get Registry Key Value
  Variable=M2COMMONFILES
  Key=SOFTWARE\M2
  Default=0
  Value Name=CommonFolder
  Flags=00000100
end
item: If/While Statement
  Variable=M2COMMONFILES
  Value=0
end
item: Set Variable
  Variable=M2COMMONFILES
  Value=%COMMON%\M2ComSys
end
item: Create Directory
  Pathname=%M2COMMONFILES%
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2
  New Value=%M2COMMONFILES%
  Value Name=CommonFolder
  Root=2
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=To get ASUS common folder files
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Get Registry Key Value
  Variable=TEMP1
  Key=SOFTWARE\M2\ASUS\1.0
  Default=0
  Value Name=InstalledPath
  Flags=00000100
end
item: If/While Statement
  Variable=TEMP1
  Value=0
end
item: Set Variable
  Variable=M2COMMSASUS
  Value=%COMMON%\M2ComSys\ASUS
end
item: Create Directory
  Pathname=%M2COMMSASUS%
end
item: Else Statement
end
item: Set Variable
  Variable=M2COMMSASUS
  Value=%TEMP1%
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Putting commom files in common folder
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
breakpoint item: Install File
  Source=h:\Common\CommDataAreaSTA.dll
  Destination=%M2COMMONFILES%\CommDataAreaSTA.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\Common\M2EventSinkCOM.dll
  Destination=%M2COMMONFILES%\M2EventSinkCOM.dll
  Flags=0001000000000010
end
item: Install File
  Source=h:\Common\QueryClient.dll
  Destination=%M2COMMONFILES%\QueryClient.dll
  Flags=0001000000000010
end
item: Install File
  Source=H:\common\QueryClient.tlb
  Destination=%M2COMMONFILES%\QueryClient.tlb
  Flags=0000000000000010
end
item: Install File
  Source=h:\Common\QueryWiz.ocx
  Destination=%M2COMMONFILES%\QueryWiz.ocx
  Flags=0001000000000010
end
item: Install File
  Source=h:\Common\QwSettings.ocx
  Destination=%M2COMMONFILES%\QwSettings.ocx
  Flags=0001000000000010
end
item: Install File
  Source=h:\Common\TransactionClientCom.dll
  Destination=%M2COMMONFILES%\TransactionClientCom.dll
  Flags=0001000000000010
end
item: Remark
end
item: Open/Close INSTALL.LOG
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Putting  ASUS commom files in ASUS common folder
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Install File
  Source=H:\ASUS_Update Setup\ASUS Client SetUp LAP.EXE
  Destination=%MAINDIR%\ASUS Client SetUp LAP.EXE
  Flags=0000000000000010
end
item: Install File
  Source=H:\ASUS_Update Setup\ASUSFileInstall.EXE
  Destination=%MAINDIR%\ASUSFileInstall.EXE
  Flags=0000000000000010
end
item: Install File
  Source=H:\ASUS_Update Setup\channels.xml
  Destination=%MAINDIR%\channels.xml
  Flags=0000000000000010
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing the dependency dlls
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Check if File/Dir Exists
  Pathname=%SYS32%\libdxxmt.dll
  Title English=Telescriber 2.0 Installer
  Flags=00000100
end
item: If/While Statement
  Variable=WNTVER
  Value=4.0
end
item: Install File
  Source=h:\\Dependencies\mfc42.dll
  Destination=%SYS32%\mfc42.dll
  Flags=0001010000010011
end
item: Install File
  Source=h:\\Dependencies\MSVCRT.DLL
  Destination=%SYS32%\MSVCRT.DLL
  Flags=0000010000010011
end
item: Install File
  Source=h:\\Dependencies\ATL.DLL
  Destination=%SYS32%\ATL.DLL
  Flags=0001010000010011
end
item: Install File
  Source=h:\\Dependencies\msacm32.dll
  Destination=%SYS32%\msacm32.dll
  Flags=0000010000010011
end
item: Install File
  Source=h:\\Dependencies\MSVCP60.DLL
  Destination=%SYS32%\MSVCP60.DLL
  Flags=0000010000010011
end
item: Install File
  Source=h:\\Dependencies\msvcrt20.dll
  Destination=%SYS32%\msvcrt20.dll
  Flags=0000010000010011
end
item: Install File
  Source=h:\\Dependencies\msxml.dll
  Destination=%SYS32%\msxml.dll
  Flags=0001010000010011
end
item: Install File
  Source=h:\\Dependencies\OLEPRO32.DLL
  Destination=%SYS32%\OLEPRO32.DLL
  Flags=0001010000010011
end
item: Else Statement
end
item: If/While Statement
  Variable=WNTVER
  Value=5.0
  Flags=00000111
end
item: Install File
  Source=h:\\Dependencies\mfc42.dll
  Destination=%SYS32%\mfc42.dll
  Flags=0001000000001010
end
item: Install File
  Source=h:\\Dependencies\MSVCRT.DLL
  Destination=%SYS32%\MSVCRT.DLL
  Flags=0000000000001010
end
item: Install File
  Source=h:\\Dependencies\ATL.DLL
  Destination=%SYS32%\ATL.DLL
  Flags=0001000000001010
end
item: Install File
  Source=h:\\Dependencies\msacm32.dll
  Destination=%SYS32%\msacm32.dll
  Flags=0000000000001010
end
item: Install File
  Source=h:\\Dependencies\MSVCP60.DLL
  Destination=%SYS32%\MSVCP60.DLL
  Flags=0000000000001010
end
item: Install File
  Source=h:\\Dependencies\msvcrt20.dll
  Destination=%SYS32%\msvcrt20.dll
  Flags=0000000000001010
end
item: Install File
  Source=h:\\Dependencies\msxml.dll
  Destination=%SYS32%\msxml.dll
  Flags=0001000000001010
end
item: Install File
  Source=h:\\Dependencies\OLEPRO32.DLL
  Destination=%SYS32%\OLEPRO32.DLL
  Flags=0001000000001010
end
item: Else Statement
end
item: Custom Dialog Set
  Name=Telescriber Installer
  item: Dialog
    Title English=Telescriber Installer
    Width=215
    Height=85
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=79 44 130 59
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=58 10 175 20
      Create Flags=01010000000000000000000000000000
      Text English=Unsupported Operating System.
    end
    item: Static
      Rectangle=58 26 164 36
      Create Flags=01010000000000000000000000000000
      Text English=Installation will not continue.
    end
    item: Static
      Rectangle=11 14 46 47
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
  end
end
item: Delete File
  Pathname=%MAINDIR%\*
  Flags=00000100
end
item: Exit Installation
end
item: End Block
end
item: End Block
end
item: Self-Register OCXs/DLLs
  Description English=Updating System Configuration, Please Wait...
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Putting appropriate registry if it is standalone version
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=0
  Value Name=StandAlone
  Root=2
  Data Type=3
end
item: End Block
end
item: If/While Statement
  Variable=STANDALONE
  Value=B
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=0
  Value Name=LicenseKey
  Root=194
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=1
  Value Name=StandAlone
  Root=2
  Data Type=3
end
item: End Block
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=0
  Value Name=Channels
  Root=2
  Data Type=3
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Prompting the user to assign applications to ports
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Execute Program
  Pathname=%MAINDIR%\InstallInit.exe
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: Rename File/Directory
  Old Pathname=%MAINDIR%\InstallInit.exe
  New Filename=InstallInit.oxo
end
item: Delete File
  Pathname=%MAINDIR%\InstallInit.exe
end
item: Get Registry Key Value
  Variable=CHANNELS
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=Channels
  Flags=00000100
end
item: If/While Statement
  Variable=CHANNELS
  Value=0
end
item: Delete File
  Pathname=%MAINDIR%\*
  Flags=00000100
end
item: Exit Installation
end
item: End Block
end
item: Else Statement
end
item: Custom Dialog Set
  Name=Telescriber Installer
  item: Dialog
    Title English=Telescriber Installer
    Width=215
    Height=85
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=79 44 130 59
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=58 10 175 20
      Create Flags=01010000000000000000000000000000
      Text English=Required Dialogic Software not found !
    end
    item: Static
      Rectangle=58 26 164 36
      Create Flags=01010000000000000000000000000000
      Text English=Installation will not continue.
    end
    item: Static
      Rectangle=11 15 46 48
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\insa.bmp
    end
  end
end
item: Delete File
  Pathname=%MAINDIR%\*
  Flags=00000100
end
item: Exit Installation
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Installing files for AUS
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Get Registry Key Value
  Variable=AUSINSTALL
  Key=SOFTWARE\M2\AUS\1.0\Client
  Default=%MAINDIR%\AUS
  Value Name=InstalledPath
  Flags=00000100
end
item: Install File
  Source=h:\AUS\ClientInstallationMap.xml
  Destination=%AUSINSTALL%\ClientInstallationMap.xml
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\TemplateMap.xml
  Destination=%AUSINSTALL%\TemplateMap.xml
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\channels.xml
  Destination=%AUSINSTALL%\channels.xml
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\TableMask.xml
  Destination=%AUSINSTALL%\TableMask.xml
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\MCCUpdateCollector.tlb
  Destination=%AUSINSTALL%\MCCUpdateCollector.tlb
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\MCCUpdateCollector.dll
  Destination=%AUSINSTALL%\MCCUpdateCollector.dll
  Flags=0001010000010011
end
item: Install File
  Source=h:\AUS\AUSProcessUpdate.tlb
  Destination=%AUSINSTALL%\ForSQL\AUSProcessUpdate.tlb
  Flags=0000010000010010
end
item: Check if File/Dir Exists
  Pathname=%AUSINSTALL%/UpdateCollector.dll
  Flags=00000101
end
item: Install File
  Source=h:\AUS\AUSProcessUpdate.dll
  Destination=%AUSINSTALL%\ForSQL\AUSProcessUpdate.dll
  Flags=0001010000010011
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\Microsoft\Windows\CurrentVersion\Run
  New Value=%AUSINSTALL%\AusClient.exe
  Value Name=M2 AUS
  Root=194
end
item: Else Statement
end
item: Install File
  Source=h:\AUS\AUSProcessUpdate.dll
  Destination=%AUSINSTALL%\ForSQL\AUSProcessUpdate.dll
  Flags=0001010000010011
end
item: End Block
end
item: Install File
  Source=h:\AUS\AUS Client Settings.exe
  Destination=%AUSINSTALL%\AUS Client Settings.exe
  Flags=0000010000010010
end
item: Install File
  Source=h:\AUS\AUSClient.exe
  Destination=%AUSINSTALL%\AUSClient.exe
  Flags=0000010000010010
end
item: End Block
end
item: Remark
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Adding Start Menu Shortcuts
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Set Variable
  Variable=COMMON
  Value=%COMMON%
  Flags=00010100
end
item: Check Configuration
  Flags=10011010
end
item: Set Variable
  Variable=MAINDIR
  Value=%MAINDIR%
  Flags=00010100
end
item: End Block
end
item: Check Configuration
  Flags=10111011
end
item: Get Registry Key Value
  Variable=STARTUPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%WIN%\Start Menu\Programs\StartUp
  Value Name=StartUp
  Flags=00000010
end
item: Get Registry Key Value
  Variable=DESKTOPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%WIN%\Desktop
  Value Name=Desktop
  Flags=00000010
end
item: Get Registry Key Value
  Variable=STARTMENUDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%WIN%\Start Menu
  Value Name=Start Menu
  Flags=00000010
end
item: Get Registry Key Value
  Variable=GROUPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%WIN%\Start Menu\Programs
  Value Name=Programs
  Flags=00000010
end
item: Get Registry Key Value
  Variable=CSTARTUPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%STARTUPDIR%
  Value Name=Common Startup
  Flags=00000100
end
item: Get Registry Key Value
  Variable=CDESKTOPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%DESKTOPDIR%
  Value Name=Common Desktop
  Flags=00000100
end
item: Get Registry Key Value
  Variable=CSTARTMENUDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%STARTMENUDIR%
  Value Name=Common Start Menu
  Flags=00000100
end
item: Get Registry Key Value
  Variable=CGROUPDIR
  Key=Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
  Default=%GROUPDIR%
  Value Name=Common Programs
  Flags=00000100
end
item: Set Variable
  Variable=CGROUP_SAVE
  Value=%GROUP%
end
item: Set Variable
  Variable=GROUP
  Value=%GROUPDIR%\%GROUP%
end
item: Create Shortcut
  Source English=%MAINDIR%\ChangeWave.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Tools\Change Wave.lnk
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: Create Shortcut
  Source English=%MAINDIR%\TelescriberAdmin.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Admin Utility.lnk
  Working Directory English=%MAINDIR%
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: Create Shortcut
  Source English=%MAINDIR%\Uninstal.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Uninstall Telescriber 2.0.lnk
  Icon Number English=0
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Create Shortcut
  Source English=%AUSINSTALL%\AUSClient.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\AUS\AUS Client.lnk
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: Create Shortcut
  Source English=%AUSINSTALL%\AUS Client Settings.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\AUS\AUS Settings.lnk
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: End Block
end
item: Create Shortcut
  Source English=%MAINDIR%\ChangeWave.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Tools\Change Wave.lnk
  Icon Number English=0
end
item: Create Shortcut
  Source English=%MAINDIR%\Tds_chart.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Tools\ChartView.lnk
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: Create Shortcut
  Source English=%MAINDIR%\DemoInfo Editor.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Tools\Demography.lnk
  Icon Number English=0
  Key Type English=1536
  Flags=00000001
end
item: Create Shortcut
  Source English=%MAINDIR%\Telescriber Settings.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\Settings.lnk
  Working Directory English=%MAINDIR%
  Icon Number English=0
end
item: Create Shortcut
  Source English=%AUSINSTALL%\AUSClient.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\AUS\AUS Client.lnk
  Icon Number English=0
end
item: Create Shortcut
  Source English=%AUSINSTALL%\AUS Client Settings.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\AUS\AUS Settings.lnk
  Icon Number English=0
end
item: Create Shortcut
  Source English=%MAINDIR%\MyIVR1.exe
  Destination English=%CGROUPDIR%\%CGROUP_SAVE%\ScriptGenerator.lnk
  Icon Number English=0
end
item: Else Statement
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Settings
  Command Line="%MAINDIR%\Telescriber Settings.exe"
  Default Directory=%MAINDIR%
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Change Wave
  Command Line=%MAINDIR%\ChangeWave.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Settings
  Command Line=%MAINDIR%\Telescriber Settings.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=AUS Client
  Command Line=%AUSINSTALL%\AUSClient.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=AUS Settings
  Command Line=%AUSINSTALL%\AUS Client Settings.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=ScriptGenerator
  Command Line=%MAINDIR%\MyIVR1.exe
end
item: Add ProgMan Icon
  Group=%GROUP%\Tools
  Icon Name English=Chart View
  Command Line=%MAINDIR%\Tds_chart.exe
end
item: Add ProgMan Icon
  Group=%GROUP%\Tools
  Icon Name English=Change Wave
  Command Line=%MAINDIR%\ChangeWave.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Uninstall Telescriber 2.0
  Command Line=%MAINDIR%\Uninstal.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Admin Utility
  Command Line=%MAINDIR%\TelescriberAdmin.exe
  Default Directory=%MAINDIR%
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Settings
  Command Line=%MAINDIR%\Telescriber Settings.exe
end
item: Add ProgMan Icon
  Group=%GROUP%
  Icon Name English=Transactor 2.0
  Command Line=%MAINDIR%\TransactorTray.exe
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Add ProgMan Icon
  Group=%GROUP%\AUS
  Icon Name English=AUS Client
  Command Line=%AUSINSTALL%\AUSClient.exe
end
item: Add ProgMan Icon
  Group=%GROUP%\AUS
  Icon Name English=AUS Settings
  Command Line=%AUSINSTALL%\AUS Client Settings.exe
end
item: End Block
end
item: End Block
end
item: Edit Registry
  Total Keys=12
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=ActiveAudioCodec
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=NULL
    Value Name=AdminMailID
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=AdminRefreshRate
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=NULL
    Value Name=DCPrimaryIP
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=DCPrimaryPort
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=NULL
    Value Name=MailServerName
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=NewDocTimeInterval
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=StationID
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=StatusTimeInterval
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=TrxTimeInterval
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=NULL
    Value Name=RootDir
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    Value Name=PhoneNo
    Root=2
  end
end
item: Edit Registry
  Total Keys=22
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    Value Name=ConnectString
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    Value Name=DCSecondaryIP
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=DCSecondaryPort
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=+5:30
    Value Name=GMTValue
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    Value Name=MailServerIP
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=mail.xml
    Value Name=MailXMLFile
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=waves
    Value Name=PromptFolder
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=Prompts.xml
    Value Name=PromptXMLFile
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=65
    Value Name=SequenceChar
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=1
    Value Name=SequenceNum
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=Telescriber
    Value Name=ServiceName
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=Templates.xml
    Value Name=TemplateXMLFile
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=1440
    Value Name=TurnAroundTime
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=0
    Value Name=LastPIN
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=TelescriberAdmin.xml
    Value Name=AdminXMLFile
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=5
    Value Name=PresetVolume
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=%MAINDIR%
    Value Name=InstalledPath
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=5
    Value Name=JumpTime
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=Application.xml
    Value Name=ApplicationXML
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=2
    Value Name=VSLogLevel
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=Telescriber
    Value Name=ProductName
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=5
    Value Name=PauseTime
    Root=2
    Data Type=3
  end
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=/ASY
  Value Name=AppSMA
  Root=2
end
item: Remark
end
item: Remark
  Text=Removing Auto Save Registry Entries
end
item: Remark
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Value Name=AppTelescriber
  Root=194
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Value Name=AppSMATele
  Root=194
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Value Name=AppProgressiveInsurance
  Root=194
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Writing AUS settings to registry
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Edit Registry
  Total Keys=5
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=0
    Value Name=CheckInterval
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=0
    Value Name=Port
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=NULL
    Value Name=Server
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=NULL
    Value Name=EMailTo
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=NULL
    Value Name=EMailServer
    Root=2
  end
end
item: Get Registry Key Value
  Variable=AUSSLEEP
  Key=SOFTWARE\M2\AUS\1.0\Client
  Default=86400000
  Value Name=SleepTime
  Flags=00000100
end
item: Get Registry Key Value
  Variable=AUSLOG
  Key=SOFTWARE\M2\AUS\1.0\Client
  Default=2
  Value Name=WriteLog
  Flags=00000100
end
item: Edit Registry
  Total Keys=16
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=%MAINDIR%
    Value Name=BuddyInstalledPath
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=Telescriber
    Value Name=ClientDescription
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=4
    Value Name=ClientType
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    Value Name=DbPass
    Root=2
    Data Type=4
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=Telescriber
    Value Name=DbServer
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    Value Name=DbUser
    Root=2
    Data Type=1
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=00000000000000000000000000000000
    Value Name=LastUpdated
    Root=2
    Data Type=4
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=5
    Value Name=RetryCount
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=8716315
    Value Name=TableMask
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=1
    Value Name=Updated
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=0
    Value Name=StayOn
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client
    New Value=%AUSINSTALL%
    Value Name=InstalledPath
    Root=2
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client
    New Value=%AUSLOG%
    Value Name=WriteLog
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client
    New Value=%AUSSLEEP%
    Value Name=SleepTime
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=2
    Value Name=WriteLog
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=1
    Value Name=Install
    Root=2
    Data Type=3
  end
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Prompting the user to set the Settings for Telescriber
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Execute Program
  Pathname=%MAINDIR%\TDSInstall.exe
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: Remark
end
item: End Block
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=B
end
item: Edit Registry
  Total Keys=2
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    New Value=1
    Value Name=GlobalID
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\VoiceScript\TDS\2.0
    Value Name=Destination
    Root=2
  end
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=Prompting the user to set the Settings for Telescriber StandAlone
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Execute Program
  Pathname=%MAINDIR%\TDSInstallSA.exe
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: End Block
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Get Registry Key Value
  Variable=DUPDATE
  Key=SOFTWARE\M2\AUS\1.0\Client\TDS
  Default=0
  Value Name=DataUpdateFlag
  Flags=00000100
end
item: Get Registry Key Value
  Variable=SUPDATE
  Key=SOFTWARE\M2\AUS\1.0\Client\TDS
  Default=0
  Value Name=SoftwareUpdateFlag
  Flags=00000100
end
item: Get Registry Key Value
  Variable=TUPDATE
  Key=SOFTWARE\M2\AUS\1.0\Client\TDS
  Default=0
  Value Name=TemplateUpdateFlag
  Flags=00000100
end
item: Get Registry Key Value
  Variable=DCIP
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=DCPrimaryIP
  Flags=00000100
end
item: Get Registry Key Value
  Variable=DCPORT
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=DCPrimaryPort
  Flags=00000100
end
item: Edit Registry
  Total Keys=3
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=0
    Value Name=DataUpdateFlag
    Root=2
    Data Type=4
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=%SUPDATE%
    Value Name=SoftwareUpdateFlag
    Root=2
    Data Type=3
  end
  item: Key
    Key=SOFTWARE\M2\AUS\1.0\Client\TDS
    New Value=%TUPDATE%
    Value Name=TemplateUpdateFlag
    Root=2
    Data Type=3
  end
end
item: End Block
end
item: Get Registry Key Value
  Variable=ROOTDIR
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=RootDir
  Flags=00000100
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=0
  Value Name=Channels
  Root=194
  Data Type=3
end
item: Edit Registry
  Total Keys=1
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  New Value=%THISBUILD%
  Value Name=BuildVersion
  Root=2
end
item: Remark
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Install File
  Source=h:\ClientNT.exe
  Destination=%MAINDIR%\ClientNT.exe
  Flags=0000000000000010
end
item: End Block
end
item: Remark
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
  Text=License Key Prompting and Authentication using ASUS
end
item: Remark
  Text=/////////////////////////////////////////////////
end
item: Remark
end
item: Execute Program
  Pathname=%MAINDIR%\ASUSFileInstall.EXE
  Command Line=/%MAINDIR%/10
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: Execute Program
  Pathname=%MAINDIR%\ASUSCLNT.EXE
  Command Line=/r/%MAINDIR%/M2\VoiceScript\TDS\2.0/10/2.0
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: Get Registry Key Value
  Variable=VALID_INSTALL
  Key=SOFTWARE\M2\ASUS\1.0\10
  Value Name=US
  Flags=00000100
end
item: If/While Statement
  Variable=VALID_INSTALL
  Value=5
end
item: Display Message
  Title English=ASUS Update Support
  Text English=      Do you want to enable active update processing.
  Flags=00001101
end
item: Execute Program
  Pathname=%MAINDIR%\ASUS Client SetUp LAP.EXE
  Command Line=/%MAINDIR%/M2\VoiceScript\TDS\2.0/10/2.0
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: End Block
end
item: End Block
end
item: Remark
end
item: Create Directory
  Pathname=%MAINDIR%\Templates
end
item: Create Directory
  Pathname=%MAINDIR%\QueryFail
end
item: Create Directory
  Pathname=%MAINDIR%\Mails
end
item: Create Directory
  Pathname=%MAINDIR%\Logs
end
item: Create Directory
  Pathname=%ROOTDIR%
end
item: Create Directory
  Pathname=%MAINDIR%\Log
end
item: Add Text to INSTALL.LOG
  Text=File Copy: %MAINDIR%\ASUSCLNT.exe
end
item: Add Text to INSTALL.LOG
  Text=File Copy: %MAINDIR%\Log\Client.log
end
item: Add Text to INSTALL.LOG
  Text=File Copy: %MAINDIR%\UnInstallASUS.exe
end
item: Add Text to INSTALL.LOG
  Text=Execute path: %MAINDIR%\UnInstallASUS.exe -p10
end
item: Remark
end
item: Self-Register OCXs/DLLs
  Description English=Updating System Configuration, Please Wait...
end
item: Rename File/Directory
  Old Pathname=%MAINDIR%\TDSInstall.exe
  New Filename=TDSInstall.oxo
end
item: Delete File
  Pathname=%MAINDIR%\TDSInstall.exe
end
item: If/While Statement
  Variable=STANDALONE
  Value=B
end
item: Execute Program
  Pathname=%MAINDIR%\ClientReg.exe
  Default Directory=%MAINDIR%
  Flags=00000010
end
item: End Block
end
item: Get Registry Key Value
  Variable=GLOBALID
  Key=SOFTWARE\M2\VoiceScript\TDS\2.0
  Default=0
  Value Name=GlobalID
  Flags=00000100
end
item: If/While Statement
  Variable=GLOBALID
  Value=0
  Flags=00000001
end
item: Create Service
  Service Name=Telescriber
  Executable Path=%MAINDIR%\Telescribersvc.exe
  Service Type=16
  Boot Type=2
  Error Type=0
  Display Name English=Telescriber
end
item: Execute Program
  Pathname=%MAINDIR%\TelescriberSvc.exe
  Command Line=-remove
  Flags=00000110
end
item: Execute Program
  Pathname=%MAINDIR%\TelescriberSvc.exe
  Command Line=-install
  Flags=00000110
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Execute Program
  Pathname=%MAINDIR%\StartUpdation.exe
  Default Directory=%MAINDIR%
  Flags=00000100
end
item: End Block
end
item: Else Statement
end
item: If/While Statement
  Variable=STANDALONE
  Value=A
end
item: Custom Dialog Set
  Name=Telescriber Service
  item: Dialog
    Title English=Telescriber Service
    Width=252
    Height=69
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=44 12 245 20
      Create Flags=01010000000000000000000000000000
      Text English=Please Register Telescriber 2.0 Service from AUS Settings - Install Page.
    end
    item: Push Button
      Rectangle=107 29 158 44
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=11 12 35 34
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\svcstart.bmp
    end
  end
end
item: End Block
end
item: If/While Statement
  Variable=STANDALONE
  Value=B
end
item: Custom Dialog Set
  Name=Telescriber Service
  item: Dialog
    Title English=Telescriber Service
    Width=250
    Height=69
    Font Name=Helv
    Font Size=8
    item: Static
      Rectangle=62 12 225 20
      Create Flags=01010000000000000000000000000000
      Text English=Please Register Telescriber 2.0 Service from Admin Utility.
    end
    item: Push Button
      Rectangle=107 29 158 44
      Create Flags=01010000000000010000000000000000
      Text English=OK
    end
    item: Static
      Rectangle=11 12 35 34
      Action=2
      Create Flags=01010000000000000000000000001011
      Pathname English=h:\\svcstart.bmp
    end
  end
end
item: End Block
end
item: End Block
end
item: Wizard Block
  Direction Variable=DIRECTION
  Display Variable=DISPLAY
  Bitmap Pathname=%_SMSINSTL_%\DIALOGS\TEMPLATE\WIZARD.BMP
  X Position=9
  Y Position=10
  Filler Color=8421440
  Flags=00000011
end
item: Custom Dialog Set
  Name=Finished
  Display Variable=DISPLAY
  item: Dialog
    Title Danish=%APPTITLE% Installation
    Title Dutch=Installatie van %APPTITLE%
    Title English=%APPTITLE% Installation
    Title Finnish=Asennus: %APPTITLE%
    Title French=Installation de %APPTITLE%
    Title German=Installation von %APPTITLE%
    Title Italian=Installazione di %APPTITLE%
    Title Norwegian=Installere %APPTITLE%
    Title Portuguese=Instalação de %APPTITLE%
    Title Spanish=Instalación de %APPTITLE%
    Title Swedish=Installation av %APPTITLE%
    Width=271
    Height=224
    Font Name=Helv
    Font Size=8
    item: Push Button
      Rectangle=150 187 195 202
      Variable=DIRECTION
      Value=N
      Create Flags=01010000000000010000000000000001
      Text Danish=&Udfør
      Text Dutch=&Voltooien
      Text English=&Finish
      Text Finnish=&Valmis
      Text French=Ter&miner
      Text German=&Weiter
      Text Italian=&Fine
      Text Norwegian=&Fullfør
      Text Portuguese=&Concluir
      Text Spanish=&Finalizar
      Text Swedish=S&lutför
    end
    item: Push Button
      Rectangle=105 187 150 202
      Variable=DISABLED
      Value=!
      Create Flags=01010000000000010000000000000000
      Text Danish=< &Tilbage
      Text Dutch=< &Terug
      Text English=< &Back
      Text Finnish=< &Edellinen
      Text French=< &Précédent
      Text German=< &Zurück
      Text Italian=< &Indietro
      Text Norwegian=< &Tilbake
      Text Portuguese=< &Anterior
      Text Spanish=< &Atrás
      Text Swedish=< &Föregående
    end
    item: Push Button
      Rectangle=211 187 256 202
      Variable=DISABLED
      Value=!
      Action=3
      Create Flags=01010000000000010000000000000000
      Text Danish=Annuller
      Text Dutch=Annuleren
      Text English=Cancel
      Text Finnish=Peruuta
      Text French=Annuler
      Text German=Abbrechen
      Text Italian=Annulla
      Text Norwegian=Avbryt
      Text Portuguese=Cancelar
      Text Spanish=Cancelar
      Text Swedish= Avbryt
    end
    item: Static
      Rectangle=8 180 256 181
      Action=3
      Create Flags=01010000000000000000000000000111
    end
    item: Static
      Rectangle=86 8 262 42
      Create Flags=01010000000000000000000000000000
      Flags=0000000000000001
      Name=Times New Roman
      Font Style=-24 0 0 0 700 255 0 0 0 3 2 1 18
      Text Danish=Installationen er fuldført!
      Text Dutch=De installatie is voltooid!
      Text English=Installation Completed!
      Text Finnish=Asennus on valmis.
      Text French=Installation terminée !
      Text German=Die Installation ist abgeschlossen!
      Text Italian=Installazione completata.
      Text Norwegian=Installasjonen er fullført.
      Text Portuguese=Instalação concluída!
      Text Spanish=Instalación completada.
      Text Swedish=Installationen är slutförd!
    end
    item: Static
      Rectangle=86 51 256 111
      Create Flags=01010000000000000000000000000000
      Text Danish=Installationen af %APPTITLE% er fuldført.
      Text Danish=
      Text Danish=Tryk på Udfør for at afslutte installationen.
      Text Dutch=De installatie van %APPTITLE% is geslaagd.
      Text Dutch=
      Text Dutch=Kies de knop Voltooien om de installatie af te sluiten.
      Text English=The installation of %APPTITLE% has been successfully completed.
      Text English=
      Text English=Press the Finish button to exit this installation.
      Text Finnish="Kohteen %APPTITLE% asennus on valmis. "
      Text Finnish=
      Text Finnish=Poistu asennusohjelmasta valitsemalla Valmis.
      Text French=L'installation de %APPTITLE% est réussie.
      Text French=
      Text French=Cliquez sur le bouton Terminer pour quitter ce programme d'installation.
      Text German=%APPTITLE% wurde erfolgreich installiert.
      Text German=
      Text German=Klicken Sie auf "Weiter", um die Installation zu beenden.
      Text Italian=L'installazione di %APPTITLE% è stata completata.
      Text Italian=
      Text Italian=Fare clic sul pulsante Fine per uscire dall'installazione.
      Text Norwegian=Installasjonen av %APPTITLE% er fullført.
      Text Norwegian=
      Text Norwegian=Velg Fullfør for å avslutte denne installasjonen.
      Text Portuguese=A instalação de %APPTITLE% foi concluída com êxito.
      Text Portuguese=
      Text Portuguese=Prima o botão 'Concluir' para sair desta instalação.
      Text Spanish=La instalación de %APPTITLE% terminó con éxito.
      Text Spanish=
      Text Spanish=Elija Finalizar para salir de esta instalación.
      Text Swedish=Installationen av %APPTITLE% har slutförts.
      Text Swedish=
      Text Swedish=Klicka på Slutför för att avsluta den här installationen.
    end
  end
end
item: End Block
end
item: Set Variable
  Variable=RESTART
end
item: New Event
  Name=Cancel
end
item: Include Script
  Pathname=%_SMSINSTL_%\Include\rollback.ipf
end
