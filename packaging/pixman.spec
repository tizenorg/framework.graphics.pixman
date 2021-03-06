#sbs-git:slp/pkgs/p/pixman pixman 0.26.0 67eba3516f06fef40915917d7396b68108ee6316

Name:       pixman
Summary:    Pixel manipulation library
Version:    0.26.0
Release:    4
Group:      System/Libraries
License:    MIT
URL:        http://www.x.org/
Source0:    http://xorg.freedesktop.org/archive/individual/lib/%{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(libpng12)

%description
Pixel manipulation library

%package devel
Summary:    Development components for the pixman library
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
Pixel manipulation library

%prep
%setup -q -n %{name}-%{version}

%build

%reconfigure --disable-arm-iwmmxt
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/libpixman-1*.so.*

%files devel
%defattr(-,root,root,-)
%dir %{_includedir}/pixman-1
%{_includedir}/pixman-1/pixman.h
%{_includedir}/pixman-1/pixman-version.h
%{_libdir}/libpixman-1*.so
%{_libdir}/pkgconfig/pixman-1.pc

