# $NetBSD: options.mk,v 1.6 2023/01/28 22:47:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libdbi libofx gnucash-finance-quote python
PKG_SUGGESTED_OPTIONS=	libdbi libofx gnucash-finance-quote python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnucash-finance-quote)
DEPENDS+=	p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
.endif

.if !empty(PKG_OPTIONS:Mlibofx)
CMAKE_CONFIGURE_ARGS+=	-DWITH_OFX=ON
PLIST_SRC+=	PLIST.ofx
.include "../../finance/libofx/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_OFX=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibdbi)
CMAKE_CONFIGURE_ARGS+=	-DWITH_SQL=ON
PLIST_SRC+=	PLIST.dbi
TOOL_DEPENDS+=	libdbi-driver-sqlite3-[0-9]*:../../databases/libdbi-driver-sqlite3
.include "../../databases/libdbi/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_SQL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_CONFIGURE_ARGS+=			-DWITH_PYTHON=ON
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		bindings/python/example_scripts/*.py
REPLACE_PYTHON+=		bindings/python/example_scripts/rest-api/*.py
REPLACE_PYTHON+=		gnucash/python/pycons/*.py
PY_PATCHPLIST=			yes
PLIST_SRC+=			PLIST.python

# /usr/pkg/share/gnucash/python/init.py imports gi
DEPENDS+=		${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CMAKE_CONFIGURE_ARGS+=			-DWITH_PYTHON=OFF
.endif
