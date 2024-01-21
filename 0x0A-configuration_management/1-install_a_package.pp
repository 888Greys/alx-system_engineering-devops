# Installing Flask and Werkzeug

# Ensure python3-pip is installed
package { 'python3-pip':
  ensure => installed,
}

# Install Flask with a specific version using pip
package { 'flask':
  ensure   => '2.1.0',
  provider => 'pip',
  require  => Package['python3-pip'],
}

# Install Werkzeug with a specific version using pip
package { 'werkzeug':
  ensure   => '2.0.1',
  provider => 'pip',
  require  => Package['python3-pip'],
}
