# $NetBSD: Makefile,v 1.16 2013/05/31 12:40:32 wiz Exp $
#

DISTNAME=	MooseX-AttributeHelpers-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-AttributeHelpers/
COMMENT=	Perl 5 module providing extensions to Moose attributes interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose

PERL5_PACKLIST=	auto/MooseX/AttributeHelpers/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
