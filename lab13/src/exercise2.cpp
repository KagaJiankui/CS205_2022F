template<typename T_size, class T_data>
class Example {
private:
  T_size     size;
  T_data *parray;
  T_data  _min;
  T_data  _max;

public:
  Example(T_data min, T_data max);
  Example(const T_data *array, T_size size);
  T_data &operator[](T_size index);
  bool    operator==(const Example &) const;
  bool    insert(const T_data *, T_size);
  bool    insert(T_data);
  T_data  min() const;
  T_data  max() const;
  void    min(T_data);
  void    max(T_data);
  ~Example();
};