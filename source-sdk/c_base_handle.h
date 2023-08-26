class IHandleEntity;

class CBaseHandle
{
friend class CBaseEntityList;

public:

	CBaseHandle();
	CBaseHandle( const CBaseHandle &other );
	CBaseHandle( unsigned long value );
	CBaseHandle( int iEntry, int iSerialNumber );

	void Init( int iEntry, int iSerialNumber );
	void Term();

	// Even if this returns true, Get() still can return return a non-null value.
	// This just tells if the handle has been initted with any values.
	bool IsValid() const;

	int GetEntryIndex() const;
	int GetSerialNumber() const;

	int ToInt() const;
	bool operator !=( const CBaseHandle &other ) const;
	bool operator ==( const CBaseHandle &other ) const;
	bool operator ==( const IHandleEntity* pEnt ) const;
	bool operator !=( const IHandleEntity* pEnt ) const;
	bool operator <( const CBaseHandle &other ) const;
	bool operator <( const IHandleEntity* pEnt ) const;

	// Assign a value to the handle.
	const CBaseHandle& operator=( const IHandleEntity *pEntity );
	const CBaseHandle& Set( const IHandleEntity *pEntity );

	// Use this to dereference the handle.
	// Note: this is implemented in game code (ehandle.h)
	IHandleEntity* Get() const;


protected:
	// The low NUM_SERIAL_BITS hold the index. If this value is less than MAX_EDICTS, then the entity is networkable.
	// The high NUM_SERIAL_NUM_BITS bits are the serial number.
	unsigned long	m_Index;
};
