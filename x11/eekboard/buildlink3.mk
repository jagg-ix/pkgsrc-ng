# $NetBSD: buildlink3.mk,v 1.23 2013/10/23 12:27:26 obache Exp $
#

BUILDLINK_TREE+=	eekboard

.if !defined(EEKBOARD_BUILDLINK3_MK)
EEKBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eekboard+=	eekboard>=1.0.6
BUILDLINK_PKGSRCDIR.eekboard?=	../../x11/eekboard

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# EEKBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-eekboard
