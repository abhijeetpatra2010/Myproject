Name: sample_rpm
Version: 1.0
Release: 1.0
Summary: Sample RPM package for RPM Testing
Group: Development/Tools 
License: GPL
URL: None
Source: sample_rpm.tar.gz
BuildRoot: /home/sachin/rpmbuild/%{name}-%{%version}

%description
Testing RPM package

%prep
%setup -n sample_rpm

%install
rm -rf "$RPM_BUILD_ROOT"
mkdir -p "$RPM_BUILD_ROOT/opt/sample_rpm"
cp -R * "$RPM_BUILD_ROOT/opt/sample_rpm"

%files
/opt/sample_rpm

%clean
rm -rf $RPM_BUILD_ROOT

