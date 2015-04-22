# $NetBSD: buildlink3.mk,v 1.6 2014/12/30 17:23:45 adam Exp $

BUILDLINK_TREE+=	qt5-psql

.if !defined(QT5_PSQL_BUILDLINK3_MK)
QT5_PSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-psql+=	qt5-psql>=5.4.0
BUILDLINK_ABI_DEPENDS.qt5-psql+=	qt5-psql>=5.4.0
BUILDLINK_PKGSRCDIR.qt5-psql?=	../../x11/qt5-psql

BUILDLINK_LIBDIRS.qt5-psql+=		qt5/plugins

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_PSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-psql
