pipeline {
    environment {
        // Define environment variables for the GitHub app credentials
        kredki = credentials('jenkins-winterro')
    }
    agent any
    stages {
        stage('Hello') {
            steps {
                echo 'Hello, world!'
                // Set commit status to "pending"
                sh 'curl -u $kredki_USR:$kredki_PSW https://api.github.com/repos/eadamwinter/casino/statuses/${sha} -d \'{"state": "pending", "description": "Build in progress"}\''
                
                // Run build steps here...
                
                // Set commit status to "success" or "failure"
                sh 'curl -u $kredki_USR:$kredki_PSW https://api.github.com/repos/eadamwinter/casino/statuses/${sha} -d \'{"state": "success", "description": "Build successful"}\''
            }
        }
    }
}
