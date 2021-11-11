# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# DO NOT EDIT osconfig.spec directly, changes are overwritten by osconfig.spec.in

Summary: Microsoft Azure Device OS Configuration Agent
Name: osconfig
Version: 0.4.0
Release: 1%{?dist}
Source0: %{name}-%{version}-Source.tar.gz

License: MIT
Group: Applications/File
URL: https://mscodehub.visualstudio.com/AzOsConfig
Vendor: Microsoft
Distribution: Mariner
BuildRequires: cmake
BuildRequires: build-essential
BuildRequires: tar
BuildRequires: gcc
BuildRequires: gtest
BuildRequires: gtest-devel
BuildRequires: gmock
BuildRequires: gmock-devel
BuildRequires: azure-iot-sdk-c
BuildRequires: curl
BuildRequires: openssl
BuildRequires: lttng-tools
BuildRequires: lttng-ust-devel
BuildRequires: tracelogging-devel
BuildRequires: rapidjson
Requires: tracelogging
Requires: lttng-ust

%description
Microsoft Azure Device OS Configuration Agent

%prep
%setup -c

%build
pwd
cd %{name}-%{version}-Source
mkdir build
pushd build
cmake .. -Duse_prov_client=ON -Dhsm_type_symm_key=ON -DBUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/
cmake --build .
popd

%install
pwd
cd %{name}-%{version}-Source
cd build
ls .
echo %{buildroot}
make install DESTDIR=%{buildroot}
ls -lR %{buildroot}

%clean
rm -rf $RPM_BUILD_ROOT

%preun
%systemd_preun osconfig.service

%post
%systemd_post osconfig.service
systemctl enable osconfig.service
systemctl start osconfig.service

%postun
%systemd_postun osconfig.service

%files
%defattr(-, root, root, -)
%{_bindir}/osconfig
/etc/aziot/identityd/config.d/osconfig.toml
/etc/azure-device-telemetryd/OsConfigAgentTelemetry.conf
/etc/osconfig/osconfig.conn
/etc/osconfig/osconfig_commandrunner.cache
/etc/systemd/system/osconfig.service
/usr/lib/osconfig/commandrunner.so
/usr/lib/osconfig/firewall.so
/usr/lib/osconfig/networking.so
/usr/lib/osconfig/settings.so

%changelog
* Fri Jun 25 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.4.0-1
- Latest bugfixes to CommandRunner module
- Latest bugfixes to Firewall module
- Latest bugfixes to Networking module
- Latest bugfixes to Settings module
* Fri Jun 11 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.3.6-1
- Latest bugfixes to CommandRunner module
- Latest bugfixes to Firewall module
- Latest bugfixes to Networking module
- Latest bugfixes to Settings module
* Tue Jun 8 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.3.5-1
- Latest bugfixes to Networking module
- Latest bugfixes to CommandRunner module
* Fri May 28 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.3.4-1
- Included debug symbols exporting
- Added agent daemon to auto-start
- Added networking module (preview)
- Added firewall module (preview)
* Mon Apr 5 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.3.0-1
- Added EIS agent support
- Added Modules manager
- Added modules (CommandRunner, Settings)
* Thu Jan 21 2021 Ahmed Messaoud <ahbenmes@microsoft.com> 0.2.1-1
- Initial version for Mariner/SantaCruz.