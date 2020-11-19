# $NetBSD: options.mk,v 1.20 2020/05/19 19:53:14 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk4
PKG_SUPPORTED_OPTIONS+=	gtk3-atk-bridge cups debug
PKG_SUPPORTED_OPTIONS+=	wayland x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_SUPPORTED_OPTIONS+=	quartz
.endif
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif
PKG_SUGGESTED_OPTIONS+=	gtk3-atk-bridge x11 cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/libcups/buildlink3.mk"
PLIST.cups=		yes
.else
MESON_ARGS+=		-Dprint-cups=disabled
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MESON_ARGS+=		-Ddebug=yes
.endif

PLIST_VARS+=		quartz
.if !empty(PKG_OPTIONS:Mquartz)
MESON_ARGS+=		-Dmacos-backend=true
PLIST.quartz=		yes
.else
MESON_ARGS+=		-Dmacos-backend=false
.endif

PLIST_VARS+=		wayland
.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=		yes
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
MESON_ARGS+=		-Dwayland-backend=true
.else
MESON_ARGS+=		-Dwayland-backend=false
.endif

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=		-Dx11-backend=true
MESON_ARGS+=		-Dxinerama=disabled
PLIST.x11=		yes

.  if !empty(PKG_OPTIONS:Mgtk3-atk-bridge)
BUILDLINK_API_DEPENDS.at-spi2-atk+=	at-spi2-atk>=2.6.1
.    include "../../devel/at-spi2-atk/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-atk-bridge
.  endif

BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.else
MESON_ARGS+=		-Dx11-backend=false
.endif
