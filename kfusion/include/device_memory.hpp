#pragma once

namespace kf
{
    class DeviceMemory
    {
    public:
        DeviceMemory() : size_(0), data_(0), refcount(0){};

        ~DeviceMemory();
        DeviceMemory &operator=(const DeviceMemory &other_arg);

        void create(size_t s);
        void release();

        void hostTodevice(const void *data, size_t size_);
        void deviceTohost(void *data);

        size_t memorySize();
        bool empty();
        void *data();

    private:
        size_t size_;
        void *data_;
        int *refcount;
    };
    // template<class T> inline       T* m_cuda::DeviceMemory::ptr() { return (T*)data_; }
    // template<class T> inline const T* m_cuda::DeviceMemory::ptr() const { return (const T*)data_; }
}