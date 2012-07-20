/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#include "Data.h"

QString Data::AppPath_cache;

bool Data::ff8Found()
{
	return QFile::exists(AppPath() % "/FF8.exe");
}

QString Data::AppPath()
{
	if(Config::value("dontUseRegAppPath").toBool()) {
		return Config::value("appPath").toString();
	}

	if(AppPath_cache.isNull()) {
		QSettings settings("Square Soft, Inc", "Final Fantasy VIII");
		AppPath_cache = QDir::cleanPath(settings.value("1.00/AppPath", "").toString());
	}
	return AppPath_cache;
}

const char *Data::location(int i)
{
	return i<LOC_COUNT && i>=0 ? locations[i] : "";
}

const char *Data::locations[LOC_COUNT] = {
	"???", QT_TRANSLATE_NOOP("1","Plaines d'Arkland - Balamb"), QT_TRANSLATE_NOOP("2","Monts Gaulg - Balamb"), QT_TRANSLATE_NOOP("3","Baie de Rinaul - Balamb"), QT_TRANSLATE_NOOP("4","Cap Raha - Balamb"), QT_TRANSLATE_NOOP("5","For�t de Rosfall - Timber"), QT_TRANSLATE_NOOP("6","Mandy Beach - Timber"), QT_TRANSLATE_NOOP("7","Lac Obel - Timber"), QT_TRANSLATE_NOOP("8","Vall�e de Lanker - Timber"), QT_TRANSLATE_NOOP("9","Ile Nantakhet - Timber"), QT_TRANSLATE_NOOP("10","Yaulny Canyon - Timber"), QT_TRANSLATE_NOOP("11","Val Hasberry - Dollet"), QT_TRANSLATE_NOOP("12","Cap Holy Glory - Dollet"), QT_TRANSLATE_NOOP("13","Longhorn Island - Dollet"), QT_TRANSLATE_NOOP("14","P�ninsule Malgo - Dollet"), QT_TRANSLATE_NOOP("15","Plateau Monterosa -Galbadia"),
	QT_TRANSLATE_NOOP("16","Lallapalooza Canyon - Galbadia"), QT_TRANSLATE_NOOP("17","Shenand Hill - Timber"), QT_TRANSLATE_NOOP("18","P�ninsule Gotland - Galbadia"), QT_TRANSLATE_NOOP("19","Ile de l'Enfer - Galbadia"), QT_TRANSLATE_NOOP("20","Plaine Galbadienne"), QT_TRANSLATE_NOOP("21","Wilburn Hill - Galbadia"), QT_TRANSLATE_NOOP("22","Archipel Rem - Galbadia"), QT_TRANSLATE_NOOP("23","Dingo D�sert - Galbadia"), QT_TRANSLATE_NOOP("24","Cap Winhill"), QT_TRANSLATE_NOOP("25","Archipel Humphrey - Winhill"), QT_TRANSLATE_NOOP("26","Ile Winter - Trabia"), QT_TRANSLATE_NOOP("27","Val de Solvard - Trabia"), QT_TRANSLATE_NOOP("28","Cr�te d'Eldbeak - Trabia"), "", QT_TRANSLATE_NOOP("30","Plaine d'Hawkind - Trabia"), QT_TRANSLATE_NOOP("31","Atoll Albatross -Trabia"),
	QT_TRANSLATE_NOOP("32","Vallon de Bika - Trabia"), QT_TRANSLATE_NOOP("33","P�ninsule Thor - Trabia"), "", QT_TRANSLATE_NOOP("35","Cr�te d'Heath - Trabia"), QT_TRANSLATE_NOOP("36","Trabia Crater - Trabia"), QT_TRANSLATE_NOOP("37","Mont Vienne - Trabia"), QT_TRANSLATE_NOOP("38","Plaine de Mordor - Esthar"), QT_TRANSLATE_NOOP("39","Mont Nortes - Esthar"), QT_TRANSLATE_NOOP("40","Atoll Fulcura - Esthar"), QT_TRANSLATE_NOOP("41","For�t Grandidi - Esthar"), QT_TRANSLATE_NOOP("42","Iles Millefeuilles - Esthar"), QT_TRANSLATE_NOOP("43","Grandes plaines d'Esthar"), QT_TRANSLATE_NOOP("44","Esthar City"), QT_TRANSLATE_NOOP("45","Salt Lake - Esthar"), QT_TRANSLATE_NOOP("46","C�te Ouest - Esthar"), QT_TRANSLATE_NOOP("47","Mont Sollet -Esthar"),
	QT_TRANSLATE_NOOP("48","Vall�e d'Abadan - Esthar"), QT_TRANSLATE_NOOP("49","Ile Minde - Esthar"), QT_TRANSLATE_NOOP("50","D�sert Kashkabald - Esthar"), QT_TRANSLATE_NOOP("51","Ile Paradisiaque - Esthar"), QT_TRANSLATE_NOOP("52","Pic de Talle - Esthar"), QT_TRANSLATE_NOOP("53","Atoll Shalmal - Esthar"), QT_TRANSLATE_NOOP("54","Vall�e de Lolestern - Centra"), QT_TRANSLATE_NOOP("55","Aiguille d'Almage - Centra"), QT_TRANSLATE_NOOP("56","Vallon Lenown - Centra"), QT_TRANSLATE_NOOP("57","Cap de l'espoir - Centra"), QT_TRANSLATE_NOOP("58","Mont Yorn - Centra"), QT_TRANSLATE_NOOP("59","Ile Pampa - Esthar"), QT_TRANSLATE_NOOP("60","Val Serengetti - Centra"), QT_TRANSLATE_NOOP("61","P�ninsule Nectalle - Centra"), QT_TRANSLATE_NOOP("62","Centra Crater - Centra"), QT_TRANSLATE_NOOP("63","Ile Poccarahi -Centra"),
	QT_TRANSLATE_NOOP("64","Biblioth�que - BGU"), QT_TRANSLATE_NOOP("65","Entr�e - BGU"), QT_TRANSLATE_NOOP("66","Salle de cours - BGU"), QT_TRANSLATE_NOOP("67","Caf�t�ria - BGU"), QT_TRANSLATE_NOOP("68","Niveau MD - BGU"), QT_TRANSLATE_NOOP("69","Hall 1er �tage - BGU"), QT_TRANSLATE_NOOP("70","Hall - BGU"), QT_TRANSLATE_NOOP("71","Infirmerie - BGU"), QT_TRANSLATE_NOOP("72","Dortoirs doubles - BGU"), QT_TRANSLATE_NOOP("73","Dortoirs simples - BGU"), QT_TRANSLATE_NOOP("74","Bureau proviseur - BGU"), QT_TRANSLATE_NOOP("75","Parking - BGU"), QT_TRANSLATE_NOOP("76","Salle de bal - BGU"), QT_TRANSLATE_NOOP("77","Campus - BGU"), QT_TRANSLATE_NOOP("78","Serre de combat - BGU"), QT_TRANSLATE_NOOP("79","Zone secr�te -BGU"),
	QT_TRANSLATE_NOOP("80","Corridor - BGU"), QT_TRANSLATE_NOOP("81","Temple - BGU"), QT_TRANSLATE_NOOP("82","Pont - BGU"), QT_TRANSLATE_NOOP("83","Villa Dincht - Balamb"), QT_TRANSLATE_NOOP("84","H�tel - Balamb"), QT_TRANSLATE_NOOP("85","Place centrale - Balamb"), QT_TRANSLATE_NOOP("86","Place de la gare - Balamb"), QT_TRANSLATE_NOOP("87","Port - Balamb"), QT_TRANSLATE_NOOP("88","R�sidence - Balamb"), QT_TRANSLATE_NOOP("89","Train"), QT_TRANSLATE_NOOP("90","Voiture"), QT_TRANSLATE_NOOP("91","Vaisseau"), QT_TRANSLATE_NOOP("92","Mine de souffre"), QT_TRANSLATE_NOOP("93","Place du village - Dollet"), QT_TRANSLATE_NOOP("94","Zuma Beach"), QT_TRANSLATE_NOOP("95","Port -Dollet"),
	QT_TRANSLATE_NOOP("96","Pub - Dollet"), QT_TRANSLATE_NOOP("97","H�tel - Dollet"), QT_TRANSLATE_NOOP("98","R�sidence - Dollet"), QT_TRANSLATE_NOOP("99","Tour satellite - Dollet"), QT_TRANSLATE_NOOP("100","Refuge montagneux - Dollet"), QT_TRANSLATE_NOOP("101","Centre ville - Timber"), QT_TRANSLATE_NOOP("102","Cha�ne de TV - Timber"), QT_TRANSLATE_NOOP("103","Base des Hiboux - Timber"), QT_TRANSLATE_NOOP("104","Pub - Timber"), QT_TRANSLATE_NOOP("105","H�tel - Timber"), QT_TRANSLATE_NOOP("106","Train - Timber"), QT_TRANSLATE_NOOP("107","R�sidence - Timber"), QT_TRANSLATE_NOOP("108","Ecran g�ant - Timber"), QT_TRANSLATE_NOOP("109","Centre de presse - Timber"), QT_TRANSLATE_NOOP("110","For�t de Timber"), QT_TRANSLATE_NOOP("111","Entr�e - Fac deGalbadia"),
	QT_TRANSLATE_NOOP("112","Station Fac de Galbadia"), QT_TRANSLATE_NOOP("113","Hall - Fac de Galbadia"), QT_TRANSLATE_NOOP("114","Corridor - Fac de Galbadia"), QT_TRANSLATE_NOOP("115","Salle d'attente - Fac Galbadia"), QT_TRANSLATE_NOOP("116","Salle de cours - Fac Galbadia"), QT_TRANSLATE_NOOP("117","Salle de r�union - Fac Galbadia"), QT_TRANSLATE_NOOP("118","Dortoirs - Fac de Galbadia"), QT_TRANSLATE_NOOP("119","Ascenseur - Fac de Galbadia"), QT_TRANSLATE_NOOP("120","Salle recteur - Fac Galbadia"), QT_TRANSLATE_NOOP("121","Auditorium - Fac de Galbadia"), QT_TRANSLATE_NOOP("122","Stade - Fac de Galbadia"), QT_TRANSLATE_NOOP("123","Stand - Fac de Galbadia"), QT_TRANSLATE_NOOP("124","2nde entr�e - Fac Galbadia"), QT_TRANSLATE_NOOP("125","Gymnase - Fac de Galbadia"), QT_TRANSLATE_NOOP("126","Palais pr�sident - Deling City"), QT_TRANSLATE_NOOP("127","Manoir Caraway - DelingCity"),
	QT_TRANSLATE_NOOP("128","Gare - Deling City"), QT_TRANSLATE_NOOP("129","Place centrale - Deling City"), QT_TRANSLATE_NOOP("130","H�tel - Deling City"), QT_TRANSLATE_NOOP("131","Bar - Deling City"), QT_TRANSLATE_NOOP("132","Sortie - Deling City"), QT_TRANSLATE_NOOP("133","Parade - Deling City"), QT_TRANSLATE_NOOP("134","Egout - Deling City"), QT_TRANSLATE_NOOP("135","Prison du d�sert - Galbadia"), QT_TRANSLATE_NOOP("136","D�sert"), QT_TRANSLATE_NOOP("137","Base des missiles"), QT_TRANSLATE_NOOP("138","Village de Winhill"), QT_TRANSLATE_NOOP("139","Pub - Winhill"), QT_TRANSLATE_NOOP("140","Maison vide - Winhill"), QT_TRANSLATE_NOOP("141","Manoir - Winhill"), QT_TRANSLATE_NOOP("142","R�sidence - Winhill"), QT_TRANSLATE_NOOP("143","H�tel -Winhill"),
	QT_TRANSLATE_NOOP("144","Voiture - Winhill"), QT_TRANSLATE_NOOP("145","Tombe du roi inconnu"), QT_TRANSLATE_NOOP("146","Horizon"), QT_TRANSLATE_NOOP("147","Habitations - Horizon"), QT_TRANSLATE_NOOP("148","Ecrans solaires - Horizon"), QT_TRANSLATE_NOOP("149","Villa du maire - Horizon"), QT_TRANSLATE_NOOP("150","Usine - Horizon"), QT_TRANSLATE_NOOP("151","Salle des f�tes - Horizon"), QT_TRANSLATE_NOOP("152","H�tel - Horizon"), QT_TRANSLATE_NOOP("153","R�sidence - Horizon"), QT_TRANSLATE_NOOP("154","Gare - Horizon"), QT_TRANSLATE_NOOP("155","Aqueduc d'Horizon"), QT_TRANSLATE_NOOP("156","Station baln�aire"), QT_TRANSLATE_NOOP("157","Salt Lake"), QT_TRANSLATE_NOOP("158","B�timent myst�rieux"), QT_TRANSLATE_NOOP("159","EstharCity"),
	QT_TRANSLATE_NOOP("160","Laboratoire Geyser - Esthar"), QT_TRANSLATE_NOOP("161","A�rodrome - Esthar"), QT_TRANSLATE_NOOP("162","Lunatic Pandora approche"), QT_TRANSLATE_NOOP("163","R�sidence pr�sident - Esthar"), QT_TRANSLATE_NOOP("164","Hall - R�sidence pr�sident"), QT_TRANSLATE_NOOP("165","Couloir - R�sidence pr�sident"), QT_TRANSLATE_NOOP("166","Bureau - R�sidence pr�sident"), QT_TRANSLATE_NOOP("167","Accueil - Labo Geyser"), QT_TRANSLATE_NOOP("168","Laboratoire Geyser"), QT_TRANSLATE_NOOP("169","Deleted"), QT_TRANSLATE_NOOP("170","Lunar Gate"), QT_TRANSLATE_NOOP("171","Parvis - Lunar Gate"), QT_TRANSLATE_NOOP("172","Glaci�re - Lunar gate"), QT_TRANSLATE_NOOP("173","Mausol�e - Esthar"), QT_TRANSLATE_NOOP("174","Entr�e - Mausol�e"), QT_TRANSLATE_NOOP("175","Pod de confinement -Mausol�e"),
	QT_TRANSLATE_NOOP("176","Salle de contr�le - Mausol�e"), QT_TRANSLATE_NOOP("177","Tears Point"), QT_TRANSLATE_NOOP("178","Labo Lunatic Pandora"), QT_TRANSLATE_NOOP("179","Zone d'atterrissage de secours"), QT_TRANSLATE_NOOP("180","Zone d'atterrissage officielle"), QT_TRANSLATE_NOOP("181","Lunatic Pandora"), QT_TRANSLATE_NOOP("182","Site des fouilles - Centra"), QT_TRANSLATE_NOOP("183","Orphelinat"), QT_TRANSLATE_NOOP("184","Salle de jeux - Orphelinat"), QT_TRANSLATE_NOOP("185","Dortoir - Orphelinat"), QT_TRANSLATE_NOOP("186","Jardin - Orphelinat"), QT_TRANSLATE_NOOP("187","Front de mer - Orphelinat"), QT_TRANSLATE_NOOP("188","Champ - Orphelinat"), QT_TRANSLATE_NOOP("189","Ruines de Centra"), QT_TRANSLATE_NOOP("190","Entr�e - Fac de Trabia"), QT_TRANSLATE_NOOP("191","Cimeti�re - Fac deTrabia"),
	QT_TRANSLATE_NOOP("192","Garage - Fac de Trabia"), QT_TRANSLATE_NOOP("193","Campus - Fac Trabia"), QT_TRANSLATE_NOOP("194","Amphith�atre - Fac de Trabia"), QT_TRANSLATE_NOOP("195","Stade - Fac de Trabia"), QT_TRANSLATE_NOOP("196","D�me myst�rieux"), QT_TRANSLATE_NOOP("197","Ville du d�sert - Shumi Village"), QT_TRANSLATE_NOOP("198","Ascenseur - Shumi Village"), QT_TRANSLATE_NOOP("199","Shumi Village"), QT_TRANSLATE_NOOP("200","Habitation - Shumi Village"), QT_TRANSLATE_NOOP("201","R�sidence - Shumi Village"), QT_TRANSLATE_NOOP("202","Habitat - Shumi Village"), QT_TRANSLATE_NOOP("203","H�tel - Shumi Village"), QT_TRANSLATE_NOOP("204","Trabia canyon"), QT_TRANSLATE_NOOP("205","Vaisseau des Seeds blancs"), QT_TRANSLATE_NOOP("206","Navire des Seeds Blancs"), QT_TRANSLATE_NOOP("207","Cabine - Navire Seedsblancs"),
	QT_TRANSLATE_NOOP("208","Cockpit - Hydre"), QT_TRANSLATE_NOOP("209","Si�ge passager - Hydre"), QT_TRANSLATE_NOOP("210","Couloir - Hydre"), QT_TRANSLATE_NOOP("211","Hangar - Hydre"), QT_TRANSLATE_NOOP("212","Acc�s - Hydre"), QT_TRANSLATE_NOOP("213","Air Room - Hydre"), QT_TRANSLATE_NOOP("214","Salle de pression - Hydre"), QT_TRANSLATE_NOOP("215","Centre de recherches Deep Sea"), QT_TRANSLATE_NOOP("216","Laboratoire - Deep Sea"), QT_TRANSLATE_NOOP("217","Salle de travail - Deep Sea"), QT_TRANSLATE_NOOP("218","Fouilles - Deep Sea"), QT_TRANSLATE_NOOP("219","Salle de contr�le - Base lunaire"), QT_TRANSLATE_NOOP("220","Centre m�dical - Base lunaire"), QT_TRANSLATE_NOOP("221","Pod - Base lunaire"), QT_TRANSLATE_NOOP("222","Dock - Base lunaire"), QT_TRANSLATE_NOOP("223","Passage - Baselunaire"),
	QT_TRANSLATE_NOOP("224","Vestiaire - Base lunaire"), QT_TRANSLATE_NOOP("225","Habitats - Base lunaire"), QT_TRANSLATE_NOOP("226","Hyper Espace"), QT_TRANSLATE_NOOP("227","For�t Chocobo"), QT_TRANSLATE_NOOP("228","Jungle"), QT_TRANSLATE_NOOP("229","Citadelle d'Ultimecia - Vestibule"), QT_TRANSLATE_NOOP("230","Citadelle d'Ultimecia - Hall"), QT_TRANSLATE_NOOP("231","Citadelle d'Ultimecia - Terrasse"), QT_TRANSLATE_NOOP("232","Citadelle d'Ultimecia - Cave"), QT_TRANSLATE_NOOP("233","Citadelle d'Ultimecia - Couloir"), QT_TRANSLATE_NOOP("234","El�vateur - Citadelle"), QT_TRANSLATE_NOOP("235","Escalier - Citadelle d'Ultimecia"), QT_TRANSLATE_NOOP("236","Salle du tr�sor - Citadelle"), QT_TRANSLATE_NOOP("237","Salle de rangement - Citadelle"), QT_TRANSLATE_NOOP("238","Citadelle d'Ultimecia - Galerie"), QT_TRANSLATE_NOOP("239","Citadelle d'Ultimecia -Ecluse"),
	QT_TRANSLATE_NOOP("240","Citadelle - Armurerie"), QT_TRANSLATE_NOOP("241","Citadelle d'Ultimecia - Prison"), QT_TRANSLATE_NOOP("242","Citadelle d'Ultimecia - Foss�"), QT_TRANSLATE_NOOP("243","Citadelle d'Ultimecia - Jardin"), QT_TRANSLATE_NOOP("244","Citadelle d'Ultimecia - Chapelle"), QT_TRANSLATE_NOOP("245","Clocher - Citadelle d'Ultimecia"), QT_TRANSLATE_NOOP("246","Chambre d'Ultimecia - Citadelle"), "???", QT_TRANSLATE_NOOP("248","Citadelle d'Ultimecia"), QT_TRANSLATE_NOOP("249","Salle d'initiation"), QT_TRANSLATE_NOOP("250","Reine des cartes"), "???", "???", "???", "???", "???"
};

const char *Data::name(int i)
{
	return i<NAM_COUNT && i>=0 ? names[i] : "";
}

const char *Data::names[NAM_COUNT] = {
	QT_TR_NOOP("Squall"), QT_TR_NOOP("Zell"), QT_TR_NOOP("Irvine"), QT_TR_NOOP("Quistis"), QT_TR_NOOP("Linoa"),
	QT_TR_NOOP("Selphie"), QT_TR_NOOP("Seifer"), QT_TR_NOOP("Edea"), QT_TR_NOOP("Laguna"), QT_TR_NOOP("Kiros"),
	QT_TR_NOOP("Ward"), "", QT_TR_NOOP("Cronos"), QT_TR_NOOP("MiniMog"), QT_TR_NOOP("Boko"), QT_TR_NOOP("Angel")
};

const char *Data::magic(int i)
{
	return i<MAG_COUNT && i>=0 ? _magic[i] : "";
}

const char *Data::_magic[MAG_COUNT] = {
	"-", QT_TR_NOOP("Brasier"), QT_TR_NOOP("Brasier+"), QT_TR_NOOP("BrasierX"), QT_TR_NOOP("Glacier"), QT_TR_NOOP("Glacier+"),
	QT_TR_NOOP("GlacierX"), QT_TR_NOOP("Foudre"), QT_TR_NOOP("Foudre+"), QT_TR_NOOP("FoudreX"), QT_TR_NOOP("H2O"), QT_TR_NOOP("Rafale"), QT_TR_NOOP("Cyanure"),
	QT_TR_NOOP("Quart"), QT_TR_NOOP("Sid�ral"), QT_TR_NOOP("Fournaise"), QT_TR_NOOP("M�t�ore"), QT_TR_NOOP("Quake"), QT_TR_NOOP("Tornade"), QT_TR_NOOP("Ultima"),
	QT_TR_NOOP("Apocalypse"), QT_TR_NOOP("Soin"), QT_TR_NOOP("Soin+"), QT_TR_NOOP("Soin Max"), QT_TR_NOOP("Vie"), QT_TR_NOOP("Vie Max"), QT_TR_NOOP("R�cup"), QT_TR_NOOP("Esuna"),
	QT_TR_NOOP("Anti-sort"), QT_TR_NOOP("Carapace"), QT_TR_NOOP("Blindage"), QT_TR_NOOP("Boormg"), QT_TR_NOOP("Aura"), QT_TR_NOOP("Double"), QT_TR_NOOP("Triple"), QT_TR_NOOP("Booster"),
	QT_TR_NOOP("Somni"), QT_TR_NOOP("Stop"), QT_TR_NOOP("C�cit�"), QT_TR_NOOP("Folie"), QT_TR_NOOP("Morph�e"), QT_TR_NOOP("Aphasie"), QT_TR_NOOP("M�galith"), QT_TR_NOOP("Ankou"),
	QT_TR_NOOP("Saign�e"), QT_TR_NOOP("Supplice"), QT_TR_NOOP("Furie"), QT_TR_NOOP("D�cubitus"), QT_TR_NOOP("Zombie"), QT_TR_NOOP("Meltdown"), QT_TR_NOOP("Scan"), QT_TR_NOOP("Joobu"),
	QT_TR_NOOP("Wall"), QT_TR_NOOP("Arkange"), QT_TR_NOOP("Percent"), QT_TR_NOOP("Catastrophe"), QT_TR_NOOP("TheEnd")
};

QStringList Data::maplist()
{
	QStringList maps;
	for(int i=0 ; i<MAP_COUNT ; ++i) {
		maps.append(_maplist[i]);
	}
	return maps;
}

const char *Data::_maplist[MAP_COUNT] = {
	"wm00",
	"wm01",
	"wm02",
	"wm03",
	"wm04",
	"wm05",
	"wm06",
	"wm07",
	"wm08",
	"wm09",
	"wm10",
	"wm11",
	"wm12",
	"wm13",
	"wm14",
	"wm15",
	"wm16",
	"wm17",
	"wm18",
	"wm19",
	"wm20",
	"wm21",
	"wm22",
	"wm23",
	"wm24",
	"wm25",
	"wm26",
	"wm27",
	"wm28",
	"wm29",
	"wm30",
	"wm31",
	"wm32",
	"wm33",
	"wm34",
	"wm35",
	"wm36",
	"wm37",
	"wm38",
	"wm39",
	"wm40",
	"wm41",
	"wm42",
	"wm43",
	"wm44",
	"wm45",
	"wm46",
	"wm47",
	"wm48",
	"wm49",
	"wm50",
	"wm51",
	"wm52",
	"wm53",
	"wm54",
	"wm55",
	"wm56",
	"wm57",
	"wm58",
	"wm59",
	"wm60",
	"wm61",
	"wm62",
	"wm63",
	"wm64",
	"wm65",
	"wm66",
	"wm67",
	"wm68",
	"wm69",
	"wm70",
	"wm71",
	"testno",
	"start",
	"start0",
	"gover",
	"ending",
	"test",
	"test1",
	"test2",
	"test3",
	"test4",
	"test5",
	"test6",
	"test7",
	"test8",
	"test9",
	"test13",
	"test14",
	"testbl0",
	"testbl1",
	"testbl2",
	"testbl3",
	"testbl4",
	"testbl5",
	"testbl6",
	"testbl7",
	"testbl8",
	"testbl9",
	"testbl13",
	"testbl14",
	"testmv",
	"bccent_1",
	"bccent1a",
	"bcform_1",
	"bcform1a",
	"bcgate_1",
	"bcgate1a",
	"bchtl_1",
	"bchtl1a",
	"bchtr_1",
	"bchtr1a",
	"bcmin1_1",
	"bcmin11a",
	"bcmin2_1",
	"bcmin21a",
	"bcmin2_2",
	"bcmin22a",
	"bcmin2_3",
	"bcmin23a",
	"bcport_1",
	"bcport1a",
	"bcport1b",
	"bcport_2",
	"bcport2a",
	"bcsaka_1",
	"bcsaka1a",
	"bcsta_1",
	"bcsta1a",
	"bdenter1",
	"bdifrit1",
	"bdin1",
	"bdin2",
	"bdin3",
	"bdin4",
	"bdin5",
	"bdview1",
	"bg2f_1",
	"bg2f_11",
	"bg2f_2",
	"bg2f_21",
	"bg2f_4",
	"bg2f_22",
	"bg2f_3",
	"bg2f_31",
	"bgbook_1",
	"bgbook1a",
	"bgbook1b",
	"bgbook_2",
	"bgbook2a",
	"bgbook_3",
	"bgbook3a",
	"bgbtl_1",
	"bgcrash1",
	"bgeat_1",
	"bgeat1a",
	"bgeat_2",
	"bgeat2a",
	"bgeat_3",
	"bggate_1",
	"bggate_2",
	"bggate_4",
	"bggate_5",
	"bggate_6",
	"bggate6a",
	"bghall_1",
	"bghall1a",
	"bghall1b",
	"bghall_2",
	"bghall2a",
	"bghall_3",
	"bghall3a",
	"bghall_4",
	"bghall4a",
	"bghall_5",
	"bghall_6",
	"bghall6b",
	"bghall_7",
	"bghall_8",
	"bghoke_1",
	"bghoke_2",
	"bghoke_3",
	"bgkote_1",
	"bgkote1a",
	"bgkote_2",
	"bgkote_3",
	"bgkote3a",
	"bgkote_4",
	"bgkote_5",
	"bgmast_1",
	"bgmast_2",
	"bgmast_3",
	"bgmast_4",
	"bgmast_5",
	"bgmd1_1",
	"bgmd1_2",
	"bgmd1_3",
	"bgmd1_4",
	"bgmd2_1",
	"bgmd2_3",
	"bgmd2_4",
	"bgmd2_5",
	"bgmd2_6",
	"bgmd2_7",
	"bgmd2_8",
	"bgmd3_1",
	"bgmd3_2",
	"bgmd4_1",
	"bgmd4_2",
	"bgmd4_3",
	"bgmdele1",
	"bgmdele2",
	"bgmdele3",
	"bgmdele4",
	"bgmon_1",
	"bgmon_2",
	"bgmon_3",
	"bgmon_4",
	"bgmon_5",
	"bgmon_6",
	"bgpark_1",
	"bgpaty_1",
	"bgpaty_2",
	"bgrank1",
	"bgroad_1",
	"bgroad_2",
	"bgroad_3",
	"bgroad_4",
	"bgroad_5",
	"bgroad_6",
	"bgroad_7",
	"bgroad_9",
	"bgroom_1",
	"bgroom_3",
	"bgroom_4",
	"bgroom_5",
	"bgroom_6",
	"bgryo1_1",
	"bgryo1_2",
	"bgryo1_3",
	"bgryo1_4",
	"bgryo1_5",
	"bgryo1_6",
	"bgryo1_7",
	"bgryo1_8",
	"bgryo2_1",
	"bgryo2_2",
	"bgsecr_1",
	"bgsecr_2",
	"bgsido_1",
	"bgsido1a",
	"bgsido_2",
	"bgsido_3",
	"bgsido_4",
	"bgsido_5",
	"bgsido5a",
	"bgsido_6",
	"bgsido_7",
	"bgsido_8",
	"bgsido_9",
	"bvboat_1",
	"bvboat_2",
	"bvcar_1",
	"bvtr_1",
	"bvtr_2",
	"bvtr_3",
	"bvtr_4",
	"bvtr_5",
	"cdfield1",
	"cdfield2",
	"cdfield3",
	"cdfield4",
	"cdfield5",
	"cdfield6",
	"cdfield7",
	"cdfield8",
	"crenter1",
	"crodin1",
	"cropen1",
	"crpower1",
	"crroof1",
	"crsanc1",
	"crsphi1",
	"crtower1",
	"crtower2",
	"crtower3",
	"crview1",
	"cwwood1",
	"cwwood2",
	"cwwood3",
	"cwwood4",
	"cwwood5",
	"cwwood6",
	"cwwood7",
	"ddruins1",
	"ddruins2",
	"ddruins3",
	"ddruins4",
	"ddruins5",
	"ddruins6",
	"ddsteam1",
	"ddtower1",
	"ddtower2",
	"ddtower3",
	"ddtower4",
	"ddtower5",
	"ddtower6",
	"doan1_1",
	"doan1_2",
	"doani1_1",
	"doani1_2",
	"doani3_1",
	"doani3_2",
	"doani4_1",
	"doani4_2",
	"dogate_1",
	"dogate1a",
	"dogate_2",
	"dohtl_1",
	"dohtr_1",
	"domin2_1",
	"domt1_1",
	"domt2_1",
	"domt3_1",
	"domt3_2",
	"domt3_3",
	"domt3_4",
	"domt4_1",
	"domt5_1",
	"domt6_1",
	"doopen_1",
	"doopen1a",
	"doopen_2",
	"doopen2a",
	"doport_1",
	"dopub_1",
	"dopub_2",
	"dopub_3",
	"dosea_1",
	"dosea_2",
	"dotown_1",
	"dotown1a",
	"dotown_2",
	"dotown2a",
	"dotown_3",
	"dotown3a",
	"eaplane1",
	"eapod1",
	"ebadele1",
	"ebadele2",
	"ebadele3",
	"ebadele5",
	"ebcont1",
	"ebcont2",
	"ebexit1",
	"ebexit2",
	"ebexit3",
	"ebexit4",
	"ebexit5",
	"ebexit6",
	"ebgate1",
	"ebgate1a",
	"ebgate2",
	"ebgate2a",
	"ebgate3",
	"ebgate3a",
	"ebgate4",
	"ebgate4a",
	"ebinhi1",
	"ebinhi1a",
	"ebinlow1",
	"ebinlow2",
	"ebinmid1",
	"ebinmid4",
	"ebinmid2",
	"ebinmid5",
	"ebinmid3",
	"ebinmid6",
	"ebinto1",
	"ebinto2",
	"ebinto3",
	"ebroad11",
	"ebroad12",
	"ebroad13",
	"ebroad21",
	"ebroad22",
	"ebroad23",
	"ebroad31",
	"ebroad32",
	"ebroad33",
	"ebroad41",
	"ebroad42",
	"ebroad43",
	"ebroad5",
	"ebroad6",
	"ebroad6a",
	"ebroad7",
	"ebroad7a",
	"ebroad8",
	"ebroad8a",
	"ebroad9",
	"ebroad9a",
	"eccway11",
	"eccway15",
	"eccway12",
	"eccway16",
	"eccway13",
	"eccway14",
	"eccway21",
	"eccway22",
	"eccway23",
	"eccway31",
	"eccway32",
	"eccway33",
	"eccway41",
	"eccway42",
	"eccway43",
	"ecenc1",
	"ecenc2",
	"ecenc3",
	"ecenter1",
	"ecenter4",
	"ecenter2",
	"ecenter5",
	"ecenter3",
	"eciway11",
	"eciway15",
	"eciway12",
	"eciway16",
	"eciway13",
	"eciway14",
	"ecmall1",
	"ecmall1a",
	"ecmall1b",
	"ecmview1",
	"ecmview2",
	"ecmview3",
	"ecmway1",
	"ecmway1a",
	"ecmway1b",
	"ecopen1",
	"ecopen1a",
	"ecopen1b",
	"ecopen2",
	"ecopen2a",
	"ecopen2b",
	"ecopen3",
	"ecopen3a",
	"ecopen3b",
	"ecopen4",
	"ecopen4a",
	"ecopen4b",
	"ecoway1",
	"ecoway1a",
	"ecoway1b",
	"ecoway2",
	"ecoway2a",
	"ecoway2b",
	"ecoway3",
	"ecoway3a",
	"ecoway3b",
	"ecpview1",
	"ecpview2",
	"ecpview3",
	"ecpway1",
	"ecpway1a",
	"ecpway1b",
	"ectake1",
	"ectake2",
	"ectake3",
	"edlabo1",
	"edlabo1a",
	"edlabo1b",
	"edmoor1",
	"edview1",
	"edview1a",
	"edview1b",
	"edview2",
	"eein1",
	"eein11",
	"eein12",
	"eein3",
	"eein31",
	"eein32",
	"eeview1",
	"eeview2",
	"eeview3",
	"efbig1",
	"efenter1",
	"efenter2",
	"efenter3",
	"efpod1",
	"efpod1a",
	"efpod1b",
	"efview1",
	"efview1a",
	"efview1b",
	"efview2",
	"ehback1",
	"ehback2",
	"ehblan1",
	"ehblan2",
	"ehblan3",
	"ehdrug1",
	"ehenter1",
	"ehenter2",
	"ehhana1",
	"ehnoki1",
	"ehroom1",
	"ehsea1",
	"ehsea2",
	"elroad1",
	"elroad2",
	"elroad3",
	"elstop1",
	"elview1",
	"elview2",
	"elwall1",
	"elwall2",
	"elwall3",
	"elwall4",
	"embind1",
	"embind1a",
	"embind2",
	"emlabo1",
	"emlabo1a",
	"emlabo1b",
	"emlabo2",
	"emlobby1",
	"emlobby3",
	"emlobby2",
	"emlobby4",
	"ephall1",
	"ephall2",
	"epmeet1",
	"eproad1",
	"eproad2",
	"epwork1",
	"epwork2",
	"epwork3",
	"escont1",
	"escouse1",
	"escouse2",
	"esform1",
	"esfreez1",
	"esview1",
	"esview2",
	"etsta1",
	"etsta2",
	"ewbrdg1",
	"ewdoor1",
	"ewele1",
	"ewele2",
	"ewele3",
	"ewpanel1",
	"ewpanel2",
	"fe2f1",
	"feart1f1",
	"feart1f2",
	"feart2f1",
	"febarac1",
	"febrdg1",
	"feclock1",
	"feclock2",
	"feclock3",
	"feclock4",
	"feclock5",
	"feclock6",
	"fegate1",
	"fehall1",
	"fehall2",
	"fein1",
	"fejail1",
	"felast1",
	"felfst1",
	"felrele1",
	"feopen1",
	"feopen2",
	"feout1",
	"fepic1",
	"fepic2",
	"fepic3",
	"ferfst1",
	"feroad1",
	"feroad2",
	"ferrst1",
	"feteras1",
	"fetre1",
	"feware1",
	"fewater1",
	"fewater2",
	"fewater3",
	"fewine1",
	"fewor1",
	"fewor2",
	"feyard1",
	"ffbrdg1",
	"ffhill1",
	"ffhole1",
	"ffseed1",
	"fhbrdg1",
	"fhdeck1",
	"fhdeck2",
	"fhdeck3",
	"fhdeck4",
	"fhdeck4a",
	"fhdeck5",
	"fhdeck6",
	"fhdeck7",
	"fhdeck7a",
	"fhedge1",
	"fhedge11",
	"fhedge2",
	"fhfish1",
	"fhform1",
	"fhhtl1",
	"fhhtr1",
	"fhmin1",
	"fhpanel1",
	"fhpara11",
	"fhpara12",
	"fhparar1",
	"fhparar2",
	"fhrail2",
	"fhrail3",
	"fhroof1",
	"fhtown1",
	"fhtown21",
	"fhtown22",
	"fhtown23",
	"fhview1",
	"fhwater1",
	"fhwise11",
	"fhwise12",
	"fhwise13",
	"fhwise15",
	"fhwisef1",
	"fhwisef2",
	"gdsand1",
	"gdsand2",
	"gdsand3",
	"gdsta1",
	"gdtrain1",
	"gfcar1",
	"gfcross1",
	"gfcross2",
	"gfelone1",
	"gfelone3",
	"gfelone2",
	"gfelone4",
	"gfhtl1",
	"gfhtl1a",
	"gfhtr1",
	"gfhtr1a",
	"gflain1",
	"gflain1a",
	"gflain11",
	"gflain2",
	"gflain2a",
	"gfmin1",
	"gfmin1a",
	"gfmin2",
	"gfmin2a",
	"gfrich1",
	"gfrich1a",
	"gfview1",
	"gfview1a",
	"gfvill1",
	"gfvill1a",
	"gfvill21",
	"gfvill24",
	"gfvill22",
	"gfvill23",
	"gfvill31",
	"gfvill32",
	"ggback1",
	"ggele1",
	"gggate1",
	"gggate2",
	"gggate3",
	"gggro1",
	"gggroen1",
	"gggroen2",
	"gggym1",
	"gggym2",
	"gghall1",
	"gghall2",
	"ggkodo1",
	"ggkodo2",
	"ggkodo4",
	"ggroad1",
	"ggroad2",
	"ggroad3",
	"ggroad5",
	"ggroad6",
	"ggroad7",
	"ggroad8",
	"ggroad8a",
	"ggroad8b",
	"ggroad9",
	"ggroad9a",
	"ggroad9b",
	"ggroom1",
	"ggroom2",
	"ggroom3",
	"ggroom4",
	"ggroom6",
	"ggroom7",
	"ggsta1",
	"ggstaen1",
	"ggstaen3",
	"ggstand1",
	"ggview1",
	"ggview2",
	"ggwitch1",
	"ggwitch2",
	"glclock1",
	"glclub1",
	"glclub3",
	"glclub4",
	"glform1",
	"glfurin1",
	"glfurin4",
	"glfurin5",
	"glfurin2",
	"glfurin3",
	"glfury1",
	"glfuryb1",
	"glgate1",
	"glgate2",
	"glgate2a",
	"glgate3",
	"glgate3a",
	"glgateb1",
	"glgatei1",
	"glgatei2",
	"glhtl1",
	"glhtr1",
	"glhtr1a",
	"glkara1",
	"glkara2",
	"glmall1",
	"glmall2",
	"glprefr1",
	"glprefr2",
	"glprefr3",
	"glprein1",
	"glpreo1",
	"glpreo2",
	"glpreo3",
	"glrent1",
	"glroad1",
	"glsta1",
	"glsta2",
	"glstage1",
	"glstage3",
	"glstaup1",
	"glstaup4",
	"glstaup2",
	"glstaup5",
	"glstaup3",
	"gltown1",
	"glwater1",
	"glwater2",
	"glwater3",
	"glwater4",
	"glwater5",
	"glwitch1",
	"glyagu1",
	"gmcont1",
	"gmcont2",
	"gmden1",
	"gmhouse1",
	"gmmoni1",
	"gmout1",
	"gmpark1",
	"gmpark2",
	"gmshoot1",
	"gmtika1",
	"gmtika2",
	"gmtika3",
	"gmtika4",
	"gmtika5",
	"gnroad1",
	"gnroad2",
	"gnroad3",
	"gnroad4",
	"gnroad5",
	"gnroom1",
	"gnroom2",
	"gnroom3",
	"gnroom4",
	"gnview1",
	"gparm1",
	"gpbig1",
	"gpbig1a",
	"gpbig2",
	"gpbig2a",
	"gpbig3",
	"gpbigin1",
	"gpbigin3",
	"gpbigin2",
	"gpbigin4",
	"gpbigin5",
	"gpcell1",
	"gpcont1",
	"gpcont2",
	"gpescap1",
	"gpexit1",
	"gpexit2",
	"gpgmn1",
	"gpgmn1a",
	"gpgmn2",
	"gpgmn3",
	"gppark1",
	"gproof1",
	"gproof2",
	"gwbrook1",
	"gwenter1",
	"gwgrass1",
	"gwpool1",
	"gwpool2",
	"gwroad1",
	"rgair1",
	"rgair2",
	"rgair3",
	"rgcock1",
	"rgcock2",
	"rgcock3",
	"rgexit1",
	"rgexit2",
	"rgguest1",
	"rgguest2",
	"rgguest3",
	"rgguest4",
	"rgguest5",
	"rghang1",
	"rghang11",
	"rghang2",
	"rghatch1",
	"rgroad1",
	"rgroad11",
	"rgroad2",
	"rgroad21",
	"rgroad3",
	"rgroad31",
	"sdcore1",
	"sdcore2",
	"sdisle1",
	"seback1",
	"seback2",
	"secont1",
	"secont2",
	"sefront1",
	"sefront2",
	"sefront3",
	"sefront4",
	"seroom1",
	"seroom2",
	"ssadel1",
	"ssadel2",
	"ssblock1",
	"sscont1",
	"sscont2",
	"ssdock1",
	"sselone1",
	"sslock1",
	"ssmedi1",
	"ssmedi2",
	"sspack1",
	"sspod1",
	"sspod2",
	"sspod3",
	"ssroad1",
	"ssroad2",
	"ssroad3",
	"ssspace1",
	"ssspace2",
	"ssspace3",
	"tgcourt1",
	"tgcourt5",
	"tgcourt2",
	"tgcourt3",
	"tgcourt4",
	"tgfront1",
	"tggara1",
	"tggate1",
	"tggrave1",
	"tgroom1",
	"tgroom2",
	"tgstage1",
	"tgview1",
	"tiagit1",
	"tiagit2",
	"tiagit3",
	"tiagit4",
	"tiagit5",
	"tiback1",
	"tiback2",
	"tigate1",
	"tihtl1",
	"tihtr1",
	"tilink1",
	"tilink2",
	"timania1",
	"timania2",
	"timania3",
	"timania4",
	"timania5",
	"timin1",
	"timin21",
	"timin22",
	"tipub1",
	"tistud1",
	"tistud21",
	"tistud22",
	"titown1",
	"titown2",
	"titown3",
	"titown4",
	"titown51",
	"titown52",
	"titown6",
	"titown7",
	"titown8",
	"titrain1",
	"titv1",
	"titvout1",
	"tivisi1",
	"tivisi2",
	"tiyane1",
	"tiyane2",
	"tiyane3",
	"tmdome1",
	"tmdome2",
	"tmelder1",
	"tmele1",
	"tmgate1",
	"tmhtl1",
	"tmhtr1",
	"tmkobo1",
	"tmkobo2",
	"tmmin1",
	"tmmura1",
	"tmmura2",
	"tmsand1",
	"tvglen1",
	"tvglen2",
	"tvglen3",
	"tvglen4",
	"tvglen5",
	"laguna01",
	"laguna02",
	"laguna03",
	"laguna04",
	"laguna05",
	"laguna06",
	"laguna07",
	"laguna08",
	"laguna09",
	"laguna10",
	"laguna11",
	"laguna12",
	"laguna13",
	"laguna14",
	"gpbigin6",
	"fhtown24",
	"rgcock4",
	"rgcock5",
	"ffhole1a",
	"ehblan1a",
	"ehenter3",
	"ehroom1a",
	"eproad1a",
	"fewhite1",
	"feblack1",
	"glwitch3",
	"ehback1a",
	"ehblan1b",
	"ehenter4",
	"ehroom1b",
	"ehsea1a"
};
