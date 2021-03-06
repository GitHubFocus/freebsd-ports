# Created by: Antonio Bonifati <ant@monitor.deis.unical.it>
# $FreeBSD$

PORTNAME=	tpad
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	editors tcl tk
MASTER_SITES=	SF/tclpad/tclpad/${PORTVERSION} \
		http://monitor.deis.unical.it/ant/tpad/ \
		http://queen.rett.polimi.it/~ant/tcl/script/ \
		http://sarovar.org/download.php/382/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Windows XP (TM) enhanced Notepad clone written in Tcl/Tk

DEPRECATED=		This port depends on Tcl/Tk 8.4 , which is no longer\
			maintained. Please port it to 8.5+
EXPIRATION_DATE=	2017-10-15

LICENSE=	GPLv2+

NO_BUILD=	yes
NO_ARCH=	yes

USES=		tk:84,run
PORTDOCS=	ChangeLog bug.html conf.html embed.html index.html intro.html \
		keys.html log.html mouse.html tidy.html tidy.png todo tpad.html
PLIST_SUB=	LIBDIR=lib/tpad${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/tpad ${STAGEDIR}${PREFIX}/bin/tpad
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION}/msgs
	(cd ${WRKDIR}/lib/tpad${PORTVERSION} && ${INSTALL_DATA} *.tcl \
		${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION})
	(cd ${WRKDIR}/lib/tpad${PORTVERSION}/msgs && ${INSTALL_DATA} *.msg \
		${STAGEDIR}${PREFIX}/lib/tpad${PORTVERSION}/msgs)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/share/tpad && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s tpad tview)
	${INSTALL_MAN} ${WRKDIR}/man/man1/tpad.1 ${STAGEDIR}${MANPREFIX}/man/man1
	(cd ${STAGEDIR}${MANPREFIX}/man/man1 && ${LN} -s tpad.1.gz tview.1.gz)
	${INSTALL_DATA} ${WRKDIR}/etc/tpad.conf \
		${STAGEDIR}${PREFIX}/etc/tpad.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/share/doc/tpad && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
