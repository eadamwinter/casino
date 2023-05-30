pipeline {
    environment {
        // Define environment variables for the GitHub app credentials
        GITHUB_APP_TOKEN = credentials('sprobuj_casino')
        GITHUB_API_URL = 'https://api.github.com/repos'
        GITHUB_API_HEADERS = "-H 'Accept: application/vnd.github+json' -H 'Authorization: Bearer ${GITHUB_APP_TOKEN}'"
    }
    agent any
    stages {
        stage('Hello') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'sprobuj_casino', usernameVariable: 'GITHUB_USERNAME', passwordVariable: 'GITHUB_TOKEN')]) {
                    sh 'echo $GITHUB_USERNAME'
                    sh 'echo $GITHUB_TOKEN'
                    
                    sh 'echo polowa'
                    
                    sh """
                    GITHUB_API_HEADERS2 = "-H 'Accept: application/vnd.github+json' -H 'Authorization: Bearer $GITHUB_TOKEN"
                    """
                    
                    sh 'echo koncowa'
                    
                    sh """
                    curl -sSL -X POST ${GITHUB_API_URL}/eadamwinter/casino/statuses/${GIT_COMMIT} \
                    ${GITHUB_API_HEADERS2} \
                    -d '{"state": "pending", "description": "Build in progress"}'
                    """

                    sh """
                        curl -sSL -X POST ${GITHUB_API_URL}/eadamwinter/casino/statuses/${GIT_COMMIT} \
                        ${GITHUB_API_HEADER2} \
                        -d '{"state": "success", "description": "prrr zajebioza-to jest niemozliwe :P"}'
                    """
                }
            }
        }
        stage('Hello_org') {
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
                    ${GITHUB_API_HEADER} \
                    -d '{"state": "success", "description": "prrr zajebioza-to jest niemozliwe :P"}'
                """
            }
        }
    }
}
