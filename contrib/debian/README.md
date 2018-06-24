
Debian
====================
This directory contains files used to package skucoind/skucoin-qt
for Debian-based Linux systems. If you compile skucoind/skucoin-qt yourself, there are some useful files here.

## skucoin: URI support ##


skucoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install skucoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your skucoinqt binary to `/usr/bin`
and the `../../share/pixmaps/skucoin128.png` to `/usr/share/pixmaps`

skucoin-qt.protocol (KDE)

