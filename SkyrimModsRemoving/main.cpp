#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <string>
#include <QDirIterator>
using namespace std;

bool isFilePlayable(QString fileName);
bool isFolderPlayable(QString folderName);
void showModFiles(QString pathToGame);
bool isFoldersGameSkyrim(QString pathToGame);
void removeAllMods(QString pathToGame);
void removeAllModsFolders(QString pathToGame);

int main()
{
	setlocale(LC_ALL, "rus");

	int i = 0;
	QString pathToGame = QDir::currentPath();
	QFileInfo fileInfo = pathToGame;

	if (!isFoldersGameSkyrim(pathToGame)) { cout << "Программа находиться не в корне папки скайрима!(Переместите программу в корень папки скайрим, где находиться exe игры)" << endl; system("pause"); return -1; }

	showModFiles(pathToGame);
	system("cls");

	cout << "Вы хотите удалить все моды? (Y - да, N - нет)" << endl;
	string question = "";
	cin >> question;

	if (question != "Y" && question != "N") exit(-1);
	if (question == "N") exit(0);
	if (question == "Y") {

		removeAllMods(pathToGame); 
		removeAllModsFolders(pathToGame + "\\" + "Data");
		removeAllModsFolders(pathToGame + "\\" + "Data" + "\\" + "Interface");
		removeAllModsFolders(pathToGame + "\\" + "Data" + "\\" + "Video");
		removeAllModsFolders(pathToGame + "\\" + "Data" + "\\" + "Strings");
	}

	system("cls");
	cout << "Завершенно!" << endl;

	system("pause");
	return 0;
}

bool isFoldersGameSkyrim(QString pathToGame)
{
	QDir dir(pathToGame);
	QFileInfoList fileList = dir.entryInfoList();

	foreach(QFileInfo file, fileList)
	{
		if (file.fileName() != ".." && file.fileName() != "." && file.suffix() != nullptr) {

			if (file.fileName() == "TESV.exe" || file.fileName() == "SkyrimLauncher.exe") return true;
		}
	}

	return false;
}

void showModFiles(QString pathToGame)
{
	QDirIterator it(pathToGame, QDirIterator::Subdirectories);

	while (it.hasNext()) {
		QFileInfo file = it.next();

		if (file.fileName() != ".." && file.fileName() != "." && file.suffix() != nullptr) {

			if (!isFilePlayable(file.fileName())) {

				cout << file.absoluteFilePath().toUtf8().constData() << endl;
			}
		}
		else if (file.fileName() != ".." && file.fileName() != "." && file.suffix() == nullptr) {

			if (!isFolderPlayable(file.fileName())) {

				cout << file.absoluteFilePath().toUtf8().constData() << endl;
			}
		}
	}
}

void removeAllMods(QString pathToGame)
{
	QDirIterator it(pathToGame, QDirIterator::Subdirectories);

	while (it.hasNext()) {
		QFileInfo file = it.next();

		if (file.fileName() != ".." && file.fileName() != "." && file.suffix() != nullptr) {

			if (!isFilePlayable(file.fileName())) {

				cout << file.absoluteFilePath().toUtf8().constData() << endl;
				QFile::remove(file.absoluteFilePath());
			}
		}
	}
}

void removeAllModsFolders(QString pathToGame)
{
	QDir dir(pathToGame);
	QFileInfoList fileList = dir.entryInfoList();

	foreach(QFileInfo file, fileList)
	{
		if (file.fileName() != ".." && file.fileName() != "." && file.suffix() == nullptr) {

			if (!isFolderPlayable(file.fileName())) {

				cout << file.absoluteFilePath().toUtf8().constData() << endl;
				QDir dir(file.absoluteFilePath());
				dir.removeRecursively();
			}
		}
	}
}

bool isFilePlayable(QString fileName)
{
	QString skyrimFilesArray[212] =
	{
		"atimgpud.dll",
		"binkw32.dll",
		"ControlMap_Custom.txt",
		"high.ini",
		"installscript.vdf",
		"low.ini",
		"medium.ini",
		"Skyrim_Default.ini",
		"SkyrimLauncher.exe",
		"steam_api.dll",
		"TESV.exe",
		"VeryHigh.ini",
		"Qt5Cored.dll",
		"SkyrimModsRemoving.exe",
		"debug.log",
		"Dawnguard.bsa",
		"Dawnguard.esm",
		"Dragonborn.bsa",
		"Dragonborn.esm",
		"HearthFires.bsa",
		"HearthFires.esm",
		"HighResTexturePack01.bsa",
		"HighResTexturePack01.esp",
		"HighResTexturePack02.bsa",
		"HighResTexturePack02.esp",
		"HighResTexturePack03.bsa",
		"HighResTexturePack03.esp",
		"Skyrim - Animations.bsa",
		"Skyrim - Interface.bsa",
		"Skyrim - Meshes.bsa",
		"Skyrim - Misc.bsa",
		"Skyrim - Shaders.bsa",
		"Skyrim - Sounds.bsa",
		"Skyrim - Textures.bsa",
		"Skyrim - Voices.bsa",
		"Skyrim - VoicesExtra.bsa",
		"Skyrim.esm",
		"Update.bsa",
		"Update.esm",
		"BGS_Logo.bik",
		"credits.txt",
		"fontconfig.txt",
		"fonts_console.swf",
		"fonts_ru.swf",
		"hudmenu.swf",
		"levelupmenu.swf",
		"Translate_RUSSIAN.txt",
		"Dawnguard_russian.DLSTRINGS",
		"Dawnguard_russian.ILSTRINGS",
		"Dawnguard_russian.STRINGS",
		"Dragonborn_russian.DLSTRINGS",
		"Dragonborn_russian.ILSTRINGS",
		"Dragonborn_russian.STRINGS",
		"Hearthfires_Russian.DLSTRINGS",
		"Hearthfires_Russian.ILSTRINGS",
		"Hearthfires_Russian.STRINGS",
		"Skyrim_Russian.DLSTRINGS",
		"Skyrim_Russian.ILSTRINGS",
		"Skyrim_Russian.STRINGS",
		"Update_Russian.DLSTRINGS",
		"Update_Russian.ILSTRINGS",
		"Update_Russian.STRINGS",
		"vcredist_x86.exe",
		"SkyrimPrefs.ini",
		"dotnetfx35setup.exe",
		"Apr2005_d3dx9_25_x64.cab",
"Apr2005_d3dx9_25_x86.cab",
"Apr2006_d3dx9_30_x64.cab",
"Apr2006_d3dx9_30_x86.cab",
"Apr2006_MDX1_x86.cab",
"Apr2006_MDX1_x86_Archive.cab",
"Apr2006_XACT_x64.cab",
"Apr2006_XACT_x86.cab",
"Apr2006_xinput_x64.cab",
"Apr2006_xinput_x86.cab",
"APR2007_d3dx10_33_x64.cab",
"APR2007_d3dx10_33_x86.cab",
"APR2007_d3dx9_33_x64.cab",
"APR2007_d3dx9_33_x86.cab",
"APR2007_XACT_x64.cab",
"APR2007_XACT_x86.cab",
"APR2007_xinput_x64.cab",
"APR2007_xinput_x86.cab",
"Aug2005_d3dx9_27_x64.cab",
"Aug2005_d3dx9_27_x86.cab",
"AUG2006_XACT_x64.cab",
"AUG2006_XACT_x86.cab",
"AUG2006_xinput_x64.cab",
"AUG2006_xinput_x86.cab",
"AUG2007_d3dx10_35_x64.cab",
"AUG2007_d3dx10_35_x86.cab",
"AUG2007_d3dx9_35_x64.cab",
"AUG2007_d3dx9_35_x86.cab",
"AUG2007_XACT_x64.cab",
"AUG2007_XACT_x86.cab",
"Aug2008_d3dx10_39_x64.cab",
"Aug2008_d3dx10_39_x86.cab",
"Aug2008_d3dx9_39_x64.cab",
"Aug2008_d3dx9_39_x86.cab",
"Aug2008_XACT_x64.cab",
"Aug2008_XACT_x86.cab",
"Aug2008_XAudio_x64.cab",
"Aug2008_XAudio_x86.cab",
"Aug2009_D3DCompiler_42_x64.cab",
"Aug2009_D3DCompiler_42_x86.cab",
"Aug2009_d3dcsx_42_x64.cab",
"Aug2009_d3dcsx_42_x86.cab",
"Aug2009_d3dx10_42_x64.cab",
"Aug2009_d3dx10_42_x86.cab",
"Aug2009_d3dx11_42_x64.cab",
"Aug2009_d3dx11_42_x86.cab",
"Aug2009_d3dx9_42_x64.cab",
"Aug2009_d3dx9_42_x86.cab",
"Aug2009_XACT_x64.cab",
"Aug2009_XACT_x86.cab",
"Aug2009_XAudio_x64.cab",
"Aug2009_XAudio_x86.cab",
"BDANT.cab",
"BDAXP.cab",
"Dec2005_d3dx9_28_x64.cab",
"Dec2005_d3dx9_28_x86.cab",
"DEC2006_d3dx10_00_x64.cab",
"DEC2006_d3dx10_00_x86.cab",
"DEC2006_d3dx9_32_x64.cab",
"DEC2006_d3dx9_32_x86.cab",
"DEC2006_XACT_x64.cab",
"DEC2006_XACT_x86.cab",
"DSETUP.dll",
"dsetup32.dll",
"dxdllreg_x86.cab",
"dxnt.cab",
"DXSETUP.exe",
"dxupdate.cab",
"Feb2005_d3dx9_24_x64.cab",
"Feb2005_d3dx9_24_x86.cab",
"Feb2006_d3dx9_29_x64.cab",
"Feb2006_d3dx9_29_x86.cab",
"Feb2006_XACT_x64.cab",
"Feb2006_XACT_x86.cab",
"FEB2007_XACT_x64.cab",
"FEB2007_XACT_x86.cab",
"Feb2010_X3DAudio_x64.cab",
"Feb2010_X3DAudio_x86.cab",
"Feb2010_XACT_x64.cab",
"Feb2010_XACT_x86.cab",
"Feb2010_XAudio_x64.cab",
"Feb2010_XAudio_x86.cab",
"Jun2005_d3dx9_26_x64.cab",
"Jun2005_d3dx9_26_x86.cab",
"JUN2006_XACT_x64.cab",
"JUN2006_XACT_x86.cab",
"JUN2007_d3dx10_34_x64.cab",
"JUN2007_d3dx10_34_x86.cab",
"JUN2007_d3dx9_34_x64.cab",
"JUN2007_d3dx9_34_x86.cab",
"JUN2007_XACT_x64.cab",
"JUN2007_XACT_x86.cab",
"JUN2008_d3dx10_38_x64.cab",
"JUN2008_d3dx10_38_x86.cab",
"JUN2008_d3dx9_38_x64.cab",
"JUN2008_d3dx9_38_x86.cab",
"JUN2008_X3DAudio_x64.cab",
"JUN2008_X3DAudio_x86.cab",
"JUN2008_XACT_x64.cab",
"JUN2008_XACT_x86.cab",
"JUN2008_XAudio_x64.cab",
"JUN2008_XAudio_x86.cab",
"Mar2008_d3dx10_37_x64.cab",
"Mar2008_d3dx10_37_x86.cab",
"Mar2008_d3dx9_37_x64.cab",
"Mar2008_d3dx9_37_x86.cab",
"Mar2008_X3DAudio_x64.cab",
"Mar2008_X3DAudio_x86.cab",
"Mar2008_XACT_x64.cab",
"Mar2008_XACT_x86.cab",
"Mar2008_XAudio_x64.cab",
"Mar2008_XAudio_x86.cab",
"Mar2009_d3dx10_41_x64.cab",
"Mar2009_d3dx10_41_x86.cab",
"Mar2009_d3dx9_41_x64.cab",
"Mar2009_d3dx9_41_x86.cab",
"Mar2009_X3DAudio_x64.cab",
"Mar2009_X3DAudio_x86.cab",
"Mar2009_XACT_x64.cab",
"Mar2009_XACT_x86.cab",
"Mar2009_XAudio_x64.cab",
"Mar2009_XAudio_x86.cab",
"Nov2007_d3dx10_36_x64.cab",
"Nov2007_d3dx10_36_x86.cab",
"Nov2007_d3dx9_36_x64.cab",
"Nov2007_d3dx9_36_x86.cab",
"NOV2007_X3DAudio_x64.cab",
"NOV2007_X3DAudio_x86.cab",
"NOV2007_XACT_x64.cab",
"NOV2007_XACT_x86.cab",
"Nov2008_d3dx10_40_x64.cab",
"Nov2008_d3dx10_40_x86.cab",
"Nov2008_d3dx9_40_x64.cab",
"Nov2008_d3dx9_40_x86.cab",
"Nov2008_X3DAudio_x64.cab",
"Nov2008_X3DAudio_x86.cab",
"Nov2008_XACT_x64.cab",
"Nov2008_XACT_x86.cab",
"Nov2008_XAudio_x64.cab",
"Nov2008_XAudio_x86.cab",
"Oct2005_xinput_x64.cab",
"Oct2005_xinput_x86.cab",
"OCT2006_d3dx9_31_x64.cab",
"OCT2006_d3dx9_31_x86.cab",
"OCT2006_XACT_x64.cab",
"OCT2006_XACT_x86.cab",

	};

	for (int i = 0; i < 212; i++) {

		if (fileName == skyrimFilesArray[i]) {

			return true;
		}
	}

	return false;
}

bool isFolderPlayable(QString folderName)
{
	QString skyrimFoldersArray[8] =
	{
		"Data",
		"DirectX10",
		"DotNetFX",
		"Skyrim",
		"VCRedist",
		"Interface",
		"Strings",
		"Video"
	};

	for (int i = 0; i < 8; i++) {

		if (folderName == skyrimFoldersArray[i]) {

			return true;
		}
	}

	return false;
}
