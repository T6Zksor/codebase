#ifndef POOL_H_NRAEWOLM
#define POOL_H_NRAEWOLM

#include <cstdlib>
#include <cstring>

template<size_t max_sz>
class Pool
{
public:
	Pool();

	void*	allocate(size_t sz);
	void	deallocate(void* ptr, size_t sz);
	bool	allocateChunk(size_t sz);

private:
	static constexpr size_t node_index(size_t sz){
		return (sz + (sz_lower_bound_ - 1))/sz_lower_bound_ - 1;
	}

	static constexpr size_t align_up(size_t sz){
		return ((sz + (sz_lower_bound_ - 1)) & ~(sz_lower_bound_ -1));
	}

	static constexpr size_t sz_lower_bound_ = 8;
	static constexpr size_t nodes_cnt_ = node_index(max_sz) + 1;

	typedef union Obj_{
		Obj_* next;
		char member[1];
	} *Obj_ptr_;

	Obj_ptr_ head_[nodes_cnt_];
};

template<size_t max_sz>
Pool<max_sz>::Pool()
{
	memset(head_, 0, sizeof(head_));
}

template<size_t max_sz>
void* Pool<max_sz>::allocate(size_t sz)
{
	if (sz > max_sz) return nullptr;
	if (sz == 0) return nullptr;

	auto idx = node_index(sz);
	auto p = head_[idx];

	if (!p) {
		if (!allocateChunk(sz)) return nullptr;
		p = head_[idx];
	}

	head_[idx] = p->next;
	return p;
}

template<size_t max_sz>
void Pool<max_sz>::deallocate(void *ptr, size_t sz)
{
	if (!ptr) return;
	if (sz > max_sz) return;
	if (sz == 0) return;

	auto idx = node_index(sz);
	auto p = reinterpret_cast<Obj_ptr_>(ptr);
	p->next = head_[idx];
	head_[idx] = p;
}

template<size_t max_sz>
bool Pool<max_sz>::allocateChunk(size_t sz)
{
	size_t cnt_each_alloc = 42;
	size_t block_sz = align_up(sz);
	auto idx = node_index(sz);
	auto p = reinterpret_cast<Obj_ptr_>(malloc(cnt_each_alloc * block_sz));
	if (!p) return false;
	auto pcopy = p;
	for (size_t ii = 0; ii < cnt_each_alloc - 1; ++ii) {
		auto pnext = reinterpret_cast<char*>(p) + block_sz;
		p->next = reinterpret_cast<Obj_ptr_>(pnext);
		p = p->next;
	}
	p->next = head_[idx];
	head_[idx] = pcopy;
	return true;
}

#endif
