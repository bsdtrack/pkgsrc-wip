# $NetBSD: buildlink3.mk,v 1.2 2009/01/04 22:50:58 jakllsch Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
REMCTL_BUILDLINK3_MK:=	${REMCTL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	remctl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nremctl}
BUILDLINK_PACKAGES+=	remctl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}remctl

.if ${REMCTL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.remctl+=	remctl>=2.13
BUILDLINK_PKGSRCDIR.remctl?=	../../wip/remctl
.endif	# REMCTL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
