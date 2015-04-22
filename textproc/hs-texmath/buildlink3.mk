# $NetBSD: buildlink3.mk,v 1.9 2015/01/07 13:21:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-texmath

.if !defined(HS_TEXMATH_BUILDLINK3_MK)
HS_TEXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-texmath+=	hs-texmath>=0.8
BUILDLINK_ABI_DEPENDS.hs-texmath+=	hs-texmath>=0.8nb8
BUILDLINK_PKGSRCDIR.hs-texmath?=	../../textproc/hs-texmath

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.endif	# HS_TEXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-texmath
