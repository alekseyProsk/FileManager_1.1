#include "FileSystem.h"

void FileSystem::getDiskInfo()
{
    wstring stemp = wstring(nameDisk.begin(), nameDisk.end());
    LPCWSTR swLPW = stemp.c_str();

    UINT drive_type = GetDriveType(swLPW); // ���������� ��� �����
    cout << "���� " << nameDisk << "\n��� �����: ";
    if (drive_type == DRIVE_REMOVABLE) cout << "���� " << nameDisk << "REMOVABLE\n";
    else if (drive_type == DRIVE_FIXED) cout << "���� " << nameDisk << "FIXED\n";
    else if (drive_type == DRIVE_REMOTE) cout << "���� " << nameDisk << "REMOTE\n";
    else if (drive_type == DRIVE_CDROM) cout << "���� " << nameDisk << "CD-ROM\n";
    else if (drive_type == DRIVE_RAMDISK) cout << "���� " << nameDisk << "RAMDISK\n";
    else cout << "���� " << nameDisk << " �����������_���\n";

    char NameBuffer[MAX_PATH];
    char SysNameBuffer[MAX_PATH];
    DWORD VSNumber;
    DWORD MCLength;
    DWORD FileSF;
    LPCSTR swLPC = nameDisk.c_str();

    if (GetVolumeInformationA(swLPC, NameBuffer, sizeof(NameBuffer),
        &VSNumber, &MCLength, &FileSF, SysNameBuffer, sizeof(SysNameBuffer))) //���������� �������� ������� � �������� �����, 
                                                                                 //���� ���, �� �������� ������
    {
        cout << "�������� ������� : " << SysNameBuffer << endl;
        cout << "�������� �����   :" << VSNumber << endl;
    }


}
