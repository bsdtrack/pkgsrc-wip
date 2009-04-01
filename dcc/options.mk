# $NetBSD: options.mk,v 1.5 2009/04/01 21:02:15 pebog Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcc
PKG_SUPPORTED_OPTIONS=	dccm
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dccm
#
#
#	Enable dccm, the DCC milter interface.
#
#
.if empty(PKG_OPTIONS:Mdccm)
CONFIGURE_ARGS+=	--disable-dccm
.else
RCD_SCRIPTS+=		dccm
PLIST.dccm=		yes
do-install: dccm-install
dccm-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dccm/dccm ${DESTDIR}${PREFIX}/libexec/
.include "../../mail/libmilter/buildlink3.mk"
.endif
