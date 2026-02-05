# Clavier USB Personnalisé avec ESP32S3 Dev Module

Ce projet transforme un ESP32S3 Dev Module en un clavier USB personnalisé capable d'exécuter des commandes prédéfinies sur un ordinateur Windows. Le clavier peut ouvrir automatiquement un terminal avec des privilèges administrateur et exécuter des commandes personnalisées.

## Fonctionnalités

- Émulation de clavier USB HID
- Ouverture automatique de l'invite de commandes (CMD) avec élévation de privilèges
- Exécution de commandes personnalisées
- Configuration facile des commandes via des fichiers d'en-tête
- Compatible avec les mises en page de clavier (actuellement configuré pour AZERTY français)

## Matériel requis

- Carte ESP32S3 Dev Module
- Câble USB-C pour la programmation et l'alimentation
- Ordinateur Windows

## Installation

1. Installez l'IDE Arduino si ce n'est pas déjà fait
2. Ajoutez le gestionnaire de cartes M5Stack dans les préférences Arduino :
   - Fichier > Préférences > Paramètres > URL supplémentaires des gestionnaires de cartes
   - Ajoutez : `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Installer esp32 dans le gestionnaire de cartes
4. Installer USBHID dans le gestionnaire de bibliothèques
5. Utilisez la carte ESP32S3 Dev Module

## Structure du projet

- `main.ino` : Point d'entrée principal du programme
- `cmd_open.h` : Gère l'ouverture du terminal avec élévation de privilèges
- `command.h` : Contient les commandes personnalisées à exécuter

## Configuration

### Personnalisation des commandes

Modifiez le fichier `command.h` pour ajouter ou modifier les commandes qui seront exécutées :

```cpp
void printCmd() {
  Keyboard.println("color a");
  delay(500);
  Keyboard.println("curl ascii.live/rick");
}
```

### Délais

Vous pouvez ajuster les délais dans `cmd_open.h` si nécessaire :
- `delay(5000)` : Délai initial avant d'envoyer les commandes
- `delay(500)` : Délai entre les commandes clavier
- `delay(3000)` : Délai après la demande d'élévation de privilèges

## Utilisation

1. Branchez le ESP32S3 Dev Module à votre ordinateur via USB
2. Le programme s'exécute automatiquement après le démarrage
3. Le programme va :
   - Attendre 5 secondes
   - Ouvrir la boîte de dialogue Exécuter (Win+R)
   - Taper "cmd" et ouvrir avec élévation de privilèges (Ctrl+Shift+Enter)
   - Confirmer l'élévation de privilèges (Alt+O)
   - Exécuter les commandes définies dans `command.h`

## Personnalisation avancée

### Changer la disposition du clavier

Modifiez la ligne suivante dans `main.ino` pour utiliser une autre disposition de clavier :

```cpp
Keyboard.begin(KeyboardLayout_fr_FR);  // Pour clavier AZERTY français
```

### Ajouter des commandes supplémentaires

1. Créez une nouvelle fonction dans `command.h`
2. Appelez cette fonction depuis `setup()` dans `main.ino`

## Dépannage

- **Le clavier ne fonctionne pas** : Vérifiez que les pilotes USB sont correctement installés
- **Mauvaise disposition de clavier** : Assurez-vous que la disposition du clavier correspond à votre configuration dans le code
- **Délais trop courts** : Augmentez les valeurs de `delay()` si nécessaire

## Sécurité

⚠️ **Avertissement de sécurité** : Ce projet envoie des commandes clavier à l'ordinateur hôte. Assurez-vous de :
- Ne pas brancher ce périphérique sur des systèmes non fiables
- Vérifier le code avant de le téléverser sur votre appareil
- Être conscient que ce type de périphérique peut être utilisé à des fins malveillantes
