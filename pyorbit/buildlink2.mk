# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/26 09:13:01 marc Exp $

.if !defined(PYORBIT_BUILDLINK2_MK)
PYORBIT_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pyorbit
BUILDLINK_DEPENDS.pyorbit?=		${PYPKGPREFIX}-orbit>=1.99.4
BUILDLINK_PKGSRCDIR.pyorbit?=		../../net/pyorbit

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyorbit=${PYPKGPREFIX}-orbit
BUILDLINK_PREFIX.pyorbit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyorbit+=	include/pyorbit-2/pyorbit.h
BUILDLINK_FILES.pyorbit+=	lib/pkgconfig/pyorbit-2.pc

.include "../../net/ORBit2/buildlink2.mk"

BUILDLINK_TARGETS+=	pyorbit-buildlink

py22-orbit-buildlink: _BUILDLINK_USE

.endif	# PYORBIT_BUILDLINK2_MK
