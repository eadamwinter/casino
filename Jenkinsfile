pipeline {
    environment {
        // Define environment variables for the GitHub app credentials
        GITHUB_APP_ID = credentials('jenkins-winterro_ID')
        GITHUB_APP_PRIVATE_KEY = credentials('GITHUB_APP_PRIVATE_KEY')
    }
    agent any
    stages {
        stage('Hello') {
            steps {
                echo 'Hello, world!'
                // Set commit status to "pending"
                sh 'curl -u $GIT_USERNAME:$GIT_PASSWORD https://api.github.com/repos/eadamwinter/casino/statuses/${sha} -d \'{"state": "pending", "description": "Build in progress"}\''
                
                // Run build steps here...
                
                // Set commit status to "success" or "failure"
                sh 'curl -u $GIT_USERNAME:$GIT_PASSWORD https://api.github.com/repos/eadamwinter/casino/statuses/${sha} -d \'{"state": "success", "description": "Build successful"}\''
            }
        }
    }
}
