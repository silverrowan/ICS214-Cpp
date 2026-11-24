#pragma once


class ISerializable {
public:
	virtual ~ISerializable();
	virtual std::nullptr_t toString() = 0;


};