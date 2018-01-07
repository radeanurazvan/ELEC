#include "Guid.h"



Guid::Guid()
{
}

std::string Guid::GuidToString(GUID guid) 
{
	char guid_cstr[39];
	snprintf(guid_cstr, sizeof(guid_cstr),
		"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

	return std::string(guid_cstr);
}

std::string Guid::NewGuid()
{
	GUID gidReference;
	HRESULT hCreateGuid = CoCreateGuid(&gidReference);
	return GuidToString(gidReference);
}

