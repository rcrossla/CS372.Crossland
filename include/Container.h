Class Container{
	virtual size_t size() = 0;
virtual size_t max_size() = 0;
virtual bool empty() = 0;
virtual void swap(Container&, Container&) = 0;
virtual void clear() = 0;
}