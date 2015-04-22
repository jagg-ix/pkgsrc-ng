# $NetBSD: buildlink3.mk,v 1.4 2014/10/07 16:47:12 adam Exp $

BUILDLINK_TREE+=	mono

.if !defined(MONO_BUILDLINK3_MK)
MONO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono+=	mono>=2.8<3
BUILDLINK_ABI_DEPENDS.mono+=	mono>=2.10.9nb10
BUILDLINK_PKGSRCDIR.mono?=	../../lang/mono2
ALL_ENV+=			MONO_SHARED_DIR=${WRKDIR:Q}
BUILDLINK_CONTENTS_FILTER.mono+=	${EGREP} '(^include/|^lib/)'

.include "../../textproc/icu/buildlink3.mk"
.endif # MONO_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono
