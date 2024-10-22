//! \brief ��������� ������������� �������.
struct DynamicArray
{
private:
	//! \brief ������ �������.
	int _size;

	//! \brief ����������� �������.
	int _capacity;

	//! \brief ������.
	int* _array;

	//! \brief ������ �����.
	const int _growthFactor = 2;

	//! \brief ��������������� ������� ��� ���������� �������.
	void _resize(int newCapacity);
public:
	//! \brief ����������� �� ���������.
	DynamicArray();

	//! \brief ����������� � �������� ��������� ��������.
	DynamicArray(int initialCapacity);

	//! \brief ����������.
	~DynamicArray();

	//! \brief ���������� ������ �������.
	//! \return ������ �������.
	int GetSize();

	//! \brief ���������� ����������� �������.
	//! \brief ���������� ����������� �������.
	int GetCapacity();

	//! \brief ���������� ������.
	//! \return ������.
	int* GetArray();

	//! \brief ��������� ������� � ������.
	//! \param index ������ ��������, ���� ����� �������� �������.
	//! \param value �������� ��������.
	void AddElement(int index, int value);

	//! \brief ������� ������� ������� �� ������������� �������.
	//! \param  index ������ ��������, ������� ����� �������.
	void RemoveByIndex(int index);

	//! \brief ������� �������� �������� �� ��� ������������� ��������.
	//! \param value ���������� ��������, ������� ����� �������.
	void RemoveByValue(int value);

	//! \brief ���������� ������� �� �������
	//! \param index ������, �� �������� ����� �������� ��������.
	//! \return ���������� ��������, ������� ��������� ��� ��������.
	int GetElement(int index);

	//! \brief ��������� ������ ������� Shaker Sort.
	void SortArray();

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	void LinearSearch(int value);

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	void BinarySearch(int value);

};
