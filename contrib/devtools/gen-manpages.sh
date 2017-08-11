#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

SCICOIND=${SCICOIND:-$SRCDIR/scicoind}
SCICOINCLI=${SCICOINCLI:-$SRCDIR/scicoin-cli}
SCICOINTX=${SCICOINTX:-$SRCDIR/scicoin-tx}
SCICOINQT=${SCICOINQT:-$SRCDIR/qt/scicoin-qt}

[ ! -x $SCICOIND ] && echo "$SCICOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
SCCVER=($($SCICOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for scicoind if --version-string is not set,
# but has different outcomes for scicoin-qt and scicoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$SCICOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $SCICOIND $SCICOINCLI $SCICOINTX $SCICOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${SCCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${SCCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
