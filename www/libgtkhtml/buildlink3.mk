# $NetBSD: buildlink3.mk,v 1.43 2014/05/05 00:48:26 ryoon Exp $

BUILDLINK_TREE+=	libgtkhtml

.if !defined(LIBGTKHTML_BUILDLINK3_MK)
LIBGTKHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtkhtml+=		libgtkhtml>=2.6.0
BUILDLINK_ABI_DEPENDS.libgtkhtml+=	libgtkhtml>=2.6.3nb32
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtkhtml
