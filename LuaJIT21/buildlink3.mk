# $NetBSD$

BUILDLINK_TREE+=	LuaJIT21

.if !defined(LUAJIT21_BUILDLINK3_MK)
LUAJIT21_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.LuaJIT21+=	LuaJIT21>=2.1
BUILDLINK_PKGSRCDIR.LuaJIT21?=		../../wip/LuaJIT21
BUILDLINK_INCDIRS.LuaJIT21+=		include/luajit-2.1
.endif	# LUAJIT21_BUILDLINK3_MK

BUILDLINK_TREE+=	-LuaJIT21
