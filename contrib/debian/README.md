
Debian
====================
This directory contains files used to package scicoind/scicoin-qt
for Debian-based Linux systems. If you compile scicoind/scicoin-qt yourself, there are some useful files here.

## scicoin: URI support ##


scicoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install scicoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your scicoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/scicoin128.png` to `/usr/share/pixmaps`

scicoin-qt.protocol (KDE)

