#include "FileSystem.h"

void FileSystem::getDiskInfo()
{
    wstring stemp = wstring(nameDisk.begin(), nameDisk.end());
    LPCWSTR swLPW = stemp.c_str();

    UINT drive_type = GetDriveType(swLPW); // определяем тип диска
    cout << "Диск " << nameDisk << "\nТип диска: ";
    if (drive_type == DRIVE_REMOVABLE) cout << "Диск " << nameDisk << "REMOVABLE\n";
    else if (drive_type == DRIVE_FIXED) cout << "Диск " << nameDisk << "FIXED\n";
    else if (drive_type == DRIVE_REMOTE) cout << "Диск " << nameDisk << "REMOTE\n";
    else if (drive_type == DRIVE_CDROM) cout << "Диск " << nameDisk << "CD-ROM\n";
    else if (drive_type == DRIVE_RAMDISK) cout << "Диск " << nameDisk << "RAMDISK\n";
    else cout << "Диск " << nameDisk << " НЕИЗВЕСТНЫЙ_ТИП\n";

    char NameBuffer[MAX_PATH];
    char SysNameBuffer[MAX_PATH];
    DWORD VSNumber;
    DWORD MCLength;
    DWORD FileSF;
    LPCSTR swLPC = nameDisk.c_str();

    if (GetVolumeInformationA(swLPC, NameBuffer, sizeof(NameBuffer),
        &VSNumber, &MCLength, &FileSF, SysNameBuffer, sizeof(SysNameBuffer))) //Определяем файловую систему и серийный номер, 
                                                                                 //если тру, то проверка прошла
    {
        cout << "Файловая система : " << SysNameBuffer << endl;
        cout << "Серийный номер   :" << VSNumber << endl;
    }


}
