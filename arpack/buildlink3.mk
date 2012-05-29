# $NetBSD: buildlink3.mk,v 1.4 2012/05/29 16:37:47 asau Exp $

BUILDLINK_DEPMETHOD.arpack?=	build

BUILDLINK_TREE+=	arpack

.if !defined(ARPACK_BUILDLINK3_MK)
ARPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arpack+=	arpack>=96
BUILDLINK_PKGSRCDIR.arpack?=	../../math/arpack
.endif	# ARPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-arpack
