pipeline {
    environment {
        // Define environment variables for the GitHub app credentials
        GITHUB_APP_TOKEN = credentials('secret_casino')
        GITHUB_API_URL = 'https://api.github.com/repos'
        GITHUB_API_HEADERS = "-H 'Accept: application/vnd.github+json' -H 'Authorization: Bearer ${GITHUB_APP_TOKEN}'"
    }
    agent any
    stages {
        stage('Hello') {
            steps {
                echo 'to jest gitcommit : ${GIT_COMMIT}'
                echo "${GIT_COMMIT}"
                echo 'Hello, world!'
                // Set commit status to "pending"
                sh """
                    curl -sSL -X POST ${GITHUB_API_URL}/eadamwinter/casino/statuses/${GIT_COMMIT} \
                    ${GITHUB_API_HEADERS} \
                    -d '{"state": "pending", "description": "Build in progress"}'
                """
                
                sh """
                    curl -sSL -X POST ${GITHUB_API_URL}/eadamwinter/casino/statuses/${GIT_COMMIT} \
                    ${GITHUB_API_HEADERS} \
                    -d '{"state": "success", "description": "zajebioza"}'
                """
            }
        }
    }
}
