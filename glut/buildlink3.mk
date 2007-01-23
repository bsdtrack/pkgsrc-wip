# $NetBSD: buildlink3.mk,v 1.1 2007/01/23 17:53:42 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLUT_BUILDLINK3_MK:=	${GLUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glut
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglut}
BUILDLINK_PACKAGES+=	glut
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}glut

.if !empty(GLUT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.glut+=	glut>=3.4.2
BUILDLINK_ABI_DEPENDS.glut+=	glut>=6.4.1nb1
BUILDLINK_PKGSRCDIR.glut?=	../../wip/glut
.endif	# GLUT_BUILDLINK3_MK

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../wip/libXi/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
