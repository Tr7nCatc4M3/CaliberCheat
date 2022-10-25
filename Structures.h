#pragma once

#include "IncludeFiles.h"

#define PI	3.14159265358979323846264338327950288419716939937510

/// <summary>
/// Defining inline operations
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
struct TArray {
	friend struct FString; // https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/StringHandling/FString/

public:
	inline TArray() {
		Data = nullptr;
		Count = Max = 0;
	};

	inline int Num() const {
		return Count;
	};

	inline T& operator[](int i) {
		return Data[i];
	};

	inline const T& operator[](int i) const {
		return Data[i];
	};

	inline bool IsValidIndex(int i) const {
		return i < Num();
	}

private:
	T* Data;
	int32_t Count;
	int32_t Max;
};

// Unreal Engine 5 Classes
class UClass { // https://docs.unrealengine.com/5.0/en-US/API/Runtime/CoreUObject/UObject/UClass/
public:
	BYTE _padding_0[0x40];
	UClass* SuperClass;
};

class UObject { // https://docs.unrealengine.com/5.0/en-US/API/Runtime/CoreUObject/UObject/UObject/
public:
	PVOID VTableObject;
	DWORD ObjectFlags;
	DWORD InternalIndex;
	UClass* Class;
	BYTE _padding_0[0x8];
	UObject* Outer;

	inline BOOLEAN IsA(PVOID parentClass) {
		for (auto super = this->Class; super; super = super->SuperClass) {
			if (super == parentClass) {
				return TRUE;
			}
		}

		return FALSE;
	}
};

class FUObjectItem { // https://docs.unrealengine.com/4.26/en-US/API/Runtime/CoreUObject/UObject/FUObjectItem/
public:
	UObject* Object;
	DWORD Flags;
	DWORD ClusterIndex;
	DWORD SerialNumber;
	DWORD SerialNumber2;
};

class TUObjectArray { // https://docs.unrealengine.com/4.26/en-US/API/Runtime/CoreUObject/UObject/FUObjectArray/TUObjectArray/
public:
	FUObjectItem* Objects[9];
};

class GObjects {
public:
	TUObjectArray* ObjectArray;
	BYTE _padding_0[0xC];
	DWORD ObjectCount;
};

struct FString : private TArray<WCHAR> {
	FString() {
		Data = nullptr;
		Max = Count = 0;
	}

	FString(LPCWSTR other) {
		Max = Count = static_cast<INT>(wcslen(other));

		if (Count) {
			Data = const_cast<PWCHAR>(other);
		}
	};

	inline BOOLEAN IsValid() {
		return Data != nullptr;
	}

	inline PWCHAR c_str() {
		return Data;
	}

	std::string ToString() const {
		auto length = std::wcslen(Data);
		std::string str(length, '\0');
		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);
		return str;
	}
};

class FRotator { // https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
public:
	FRotator() : Pitch(0.f), Yaw(0.f), Roll(0.f) {
	}

	FRotator(float _Pitch, float _Yaw, float _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll) {
	}
	~FRotator() {
	}
	float Pitch;
	float Yaw;
	float Roll;
	inline FRotator get() {
		return FRotator(Pitch, Yaw, Roll);
	}
};