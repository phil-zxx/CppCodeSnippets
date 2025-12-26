#include <pybind11/pybind11.h>
#include <MyVector.hpp>
#include <Vector3.hpp>

namespace py = pybind11;

PYBIND11_MODULE(PyBindSample, m) {
    m.doc() = "pybind11 cross-module test module";

    m.def("add", [](int a, int b) { return a + b; });

    py::class_<MyVector>(m, "MyVector")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, double>())
        .def("at",          py::overload_cast<const size_t>(&MyVector::at, py::const_))
        .def("size",        &MyVector::size)
        .def("__add__",     [](const MyVector& vec1, const MyVector& vec2) { return MyVector(vec1 + vec2); })
        .def("__sub__",     [](const MyVector& vec1, const MyVector& vec2) { return MyVector(vec1 - vec2); })
        .def("__mul__",     [](const MyVector& vec1, const MyVector& vec2) { return MyVector(vec1 * vec2); })
        .def("__truediv__", [](const MyVector& vec1, const MyVector& vec2) { return MyVector(vec1 / vec2); })
        .def("__getitem__", [](MyVector& vec, const size_t& idx) { return vec[idx]; })
        .def("__setitem__", [](MyVector& vec, const size_t& idx, const double& value) { vec[idx] = value; })
        .def("__repr__",    &MyVector::toString);

    py::class_<Vector3>(m, "Vector3")
        .def(py::init<int, int, int>(), py::arg("x"), py::arg("y"), py::arg("z"))
        .def("length", &Vector3::length)
        .def_readwrite("x", &Vector3::x)
        .def_readwrite("y", &Vector3::y)
        .def_readwrite("z", &Vector3::z);

}
